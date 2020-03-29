
#include "geos-base.h"
#include "geos-coords.h"
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
std::string cpp_version_impl() {
  return GEOSversion();
}

static void __errorHandler(const char *fmt, ...) {

  char buf[BUFSIZ], *p;
  va_list ap;
  va_start(ap, fmt);
  vsprintf(buf, fmt, ap);
  va_end(ap);
  p = buf + strlen(buf) - 1;
  if(strlen(buf) > 0 && *p == '\n') *p = '\0';

  Rcpp::Function error(".stop_geos", Rcpp::Environment::namespace_env("geovctrs"));
  error(buf);

  return;
}

static void __warningHandler(const char *fmt, ...) {

  char buf[BUFSIZ], *p;
  va_list ap;
  va_start(ap, fmt);
  vsprintf(buf, fmt, ap);
  va_end(ap);
  p = buf + strlen(buf) - 1;
  if(strlen(buf) > 0 && *p == '\n') *p = '\0';

  Rcpp::Function warning("warning");
  warning(buf);

  return;
}

static void __countErrorHandler(const char *fmt, void *userdata) {
  int *i = (int *) userdata;
  *i = *i + 1;
}

static void __emptyNoticeHandler(const char *fmt, void *userdata) { }

GEOSContextHandle_t geos_init(void) {
#ifdef HAVE350
  GEOSContextHandle_t context = GEOS_init_r();
  GEOSContext_setNoticeHandler_r(context, __warningHandler);
  GEOSContext_setErrorHandler_r(context, __errorHandler);
  return context;
#else
  return initGEOS_r((GEOSMessageHandler) __warningHandler, (GEOSMessageHandler) __errorHandler);
#endif
}

void geos_finish(GEOSContextHandle_t context) {
#ifdef HAVE350
  GEOS_finish_r(context);
#else
  finishGEOS_r(context);
#endif
}
