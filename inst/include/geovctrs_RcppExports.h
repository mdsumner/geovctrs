// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#ifndef RCPP_geovctrs_RCPPEXPORTS_H_GEN_
#define RCPP_geovctrs_RCPPEXPORTS_H_GEN_

#include <Rcpp.h>

namespace geovctrs {

    using namespace Rcpp;

    namespace {
        void validateSignature(const char* sig) {
            Rcpp::Function require = Rcpp::Environment::base_env()["require"];
            require("geovctrs", Rcpp::Named("quietly") = true);
            typedef int(*Ptr_validate)(const char*);
            static Ptr_validate p_validate = (Ptr_validate)
                R_GetCCallable("geovctrs", "_geovctrs_RcppExport_validate");
            if (!p_validate(sig)) {
                throw Rcpp::function_not_exported(
                    "C++ function with signature '" + std::string(sig) + "' not found in geovctrs");
            }
        }
    }

    inline NumericVector pmin2(NumericVector x1, NumericVector x2) {
        typedef SEXP(*Ptr_pmin2)(SEXP,SEXP);
        static Ptr_pmin2 p_pmin2 = NULL;
        if (p_pmin2 == NULL) {
            validateSignature("NumericVector(*pmin2)(NumericVector,NumericVector)");
            p_pmin2 = (Ptr_pmin2)R_GetCCallable("geovctrs", "_geovctrs_pmin2");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_pmin2(Shield<SEXP>(Rcpp::wrap(x1)), Shield<SEXP>(Rcpp::wrap(x2)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<NumericVector >(rcpp_result_gen);
    }

    inline NumericVector pmax2(NumericVector x1, NumericVector x2) {
        typedef SEXP(*Ptr_pmax2)(SEXP,SEXP);
        static Ptr_pmax2 p_pmax2 = NULL;
        if (p_pmax2 == NULL) {
            validateSignature("NumericVector(*pmax2)(NumericVector,NumericVector)");
            p_pmax2 = (Ptr_pmax2)R_GetCCallable("geovctrs", "_geovctrs_pmax2");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_pmax2(Shield<SEXP>(Rcpp::wrap(x1)), Shield<SEXP>(Rcpp::wrap(x2)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<NumericVector >(rcpp_result_gen);
    }

    inline SEXP geovctrs_cpp_bbox(SEXP data, bool naRm, bool onlyFinite) {
        typedef SEXP(*Ptr_geovctrs_cpp_bbox)(SEXP,SEXP,SEXP);
        static Ptr_geovctrs_cpp_bbox p_geovctrs_cpp_bbox = NULL;
        if (p_geovctrs_cpp_bbox == NULL) {
            validateSignature("SEXP(*geovctrs_cpp_bbox)(SEXP,bool,bool)");
            p_geovctrs_cpp_bbox = (Ptr_geovctrs_cpp_bbox)R_GetCCallable("geovctrs", "_geovctrs_geovctrs_cpp_bbox");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_geovctrs_cpp_bbox(Shield<SEXP>(Rcpp::wrap(data)), Shield<SEXP>(Rcpp::wrap(naRm)), Shield<SEXP>(Rcpp::wrap(onlyFinite)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<SEXP >(rcpp_result_gen);
    }

    inline SEXP geovctrs_cpp_z_range(SEXP data, bool naRm, bool onlyFinite) {
        typedef SEXP(*Ptr_geovctrs_cpp_z_range)(SEXP,SEXP,SEXP);
        static Ptr_geovctrs_cpp_z_range p_geovctrs_cpp_z_range = NULL;
        if (p_geovctrs_cpp_z_range == NULL) {
            validateSignature("SEXP(*geovctrs_cpp_z_range)(SEXP,bool,bool)");
            p_geovctrs_cpp_z_range = (Ptr_geovctrs_cpp_z_range)R_GetCCallable("geovctrs", "_geovctrs_geovctrs_cpp_z_range");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_geovctrs_cpp_z_range(Shield<SEXP>(Rcpp::wrap(data)), Shield<SEXP>(Rcpp::wrap(naRm)), Shield<SEXP>(Rcpp::wrap(onlyFinite)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<SEXP >(rcpp_result_gen);
    }

    inline SEXP geovctrs_cpp_envelope(SEXP data, bool naRm, bool onlyFinite) {
        typedef SEXP(*Ptr_geovctrs_cpp_envelope)(SEXP,SEXP,SEXP);
        static Ptr_geovctrs_cpp_envelope p_geovctrs_cpp_envelope = NULL;
        if (p_geovctrs_cpp_envelope == NULL) {
            validateSignature("SEXP(*geovctrs_cpp_envelope)(SEXP,bool,bool)");
            p_geovctrs_cpp_envelope = (Ptr_geovctrs_cpp_envelope)R_GetCCallable("geovctrs", "_geovctrs_geovctrs_cpp_envelope");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_geovctrs_cpp_envelope(Shield<SEXP>(Rcpp::wrap(data)), Shield<SEXP>(Rcpp::wrap(naRm)), Shield<SEXP>(Rcpp::wrap(onlyFinite)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<SEXP >(rcpp_result_gen);
    }

    inline SEXP geovctrs_cpp_z_envelope(SEXP data, bool naRm, bool onlyFinite) {
        typedef SEXP(*Ptr_geovctrs_cpp_z_envelope)(SEXP,SEXP,SEXP);
        static Ptr_geovctrs_cpp_z_envelope p_geovctrs_cpp_z_envelope = NULL;
        if (p_geovctrs_cpp_z_envelope == NULL) {
            validateSignature("SEXP(*geovctrs_cpp_z_envelope)(SEXP,bool,bool)");
            p_geovctrs_cpp_z_envelope = (Ptr_geovctrs_cpp_z_envelope)R_GetCCallable("geovctrs", "_geovctrs_geovctrs_cpp_z_envelope");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_geovctrs_cpp_z_envelope(Shield<SEXP>(Rcpp::wrap(data)), Shield<SEXP>(Rcpp::wrap(naRm)), Shield<SEXP>(Rcpp::wrap(onlyFinite)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<SEXP >(rcpp_result_gen);
    }

    inline SEXP geovctrs_cpp_convert(SEXP data, SEXP ptype) {
        typedef SEXP(*Ptr_geovctrs_cpp_convert)(SEXP,SEXP);
        static Ptr_geovctrs_cpp_convert p_geovctrs_cpp_convert = NULL;
        if (p_geovctrs_cpp_convert == NULL) {
            validateSignature("SEXP(*geovctrs_cpp_convert)(SEXP,SEXP)");
            p_geovctrs_cpp_convert = (Ptr_geovctrs_cpp_convert)R_GetCCallable("geovctrs", "_geovctrs_geovctrs_cpp_convert");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_geovctrs_cpp_convert(Shield<SEXP>(Rcpp::wrap(data)), Shield<SEXP>(Rcpp::wrap(ptype)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<SEXP >(rcpp_result_gen);
    }

    inline LogicalVector geovctrs_cpp_has_missing(SEXP x) {
        typedef SEXP(*Ptr_geovctrs_cpp_has_missing)(SEXP);
        static Ptr_geovctrs_cpp_has_missing p_geovctrs_cpp_has_missing = NULL;
        if (p_geovctrs_cpp_has_missing == NULL) {
            validateSignature("LogicalVector(*geovctrs_cpp_has_missing)(SEXP)");
            p_geovctrs_cpp_has_missing = (Ptr_geovctrs_cpp_has_missing)R_GetCCallable("geovctrs", "_geovctrs_geovctrs_cpp_has_missing");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_geovctrs_cpp_has_missing(Shield<SEXP>(Rcpp::wrap(x)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<LogicalVector >(rcpp_result_gen);
    }

    inline LogicalVector geovctrs_cpp_has_missing_or_infinite(SEXP x) {
        typedef SEXP(*Ptr_geovctrs_cpp_has_missing_or_infinite)(SEXP);
        static Ptr_geovctrs_cpp_has_missing_or_infinite p_geovctrs_cpp_has_missing_or_infinite = NULL;
        if (p_geovctrs_cpp_has_missing_or_infinite == NULL) {
            validateSignature("LogicalVector(*geovctrs_cpp_has_missing_or_infinite)(SEXP)");
            p_geovctrs_cpp_has_missing_or_infinite = (Ptr_geovctrs_cpp_has_missing_or_infinite)R_GetCCallable("geovctrs", "_geovctrs_geovctrs_cpp_has_missing_or_infinite");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_geovctrs_cpp_has_missing_or_infinite(Shield<SEXP>(Rcpp::wrap(x)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<LogicalVector >(rcpp_result_gen);
    }

    inline List geovctrs_cpp_summary(SEXP x) {
        typedef SEXP(*Ptr_geovctrs_cpp_summary)(SEXP);
        static Ptr_geovctrs_cpp_summary p_geovctrs_cpp_summary = NULL;
        if (p_geovctrs_cpp_summary == NULL) {
            validateSignature("List(*geovctrs_cpp_summary)(SEXP)");
            p_geovctrs_cpp_summary = (Ptr_geovctrs_cpp_summary)R_GetCCallable("geovctrs", "_geovctrs_geovctrs_cpp_summary");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_geovctrs_cpp_summary(Shield<SEXP>(Rcpp::wrap(x)));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (Rcpp::internal::isLongjumpSentinel(rcpp_result_gen))
            throw Rcpp::LongjumpException(rcpp_result_gen);
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(Rcpp::as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<List >(rcpp_result_gen);
    }

}

#endif // RCPP_geovctrs_RCPPEXPORTS_H_GEN_
