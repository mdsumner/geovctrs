
#' Line segments
#'
#' The [geo_segment()] type is useful as an efficient representation of
#' line segments stored using column vectors.
#' Note that `geo_segment(geo_xy(NA, NA), geo_xy(NA, NA))` is considered
#' an "empty" linestring, whereas `geo_segment(geo_xy(NA, NA), geo_xy(NA, NA), srid = NA)`
#' is "missing" (see [geo_is_missing()] and [geo_is_empty()]).
#'
#' @param start,end [geo_xy()]s for the start and end
#'   of the segment, respectively.
#' @inheritParams geo_srid
#'
#' @return A [new_geovctrs_segment()]
#' @export
#'
#' @examples
#' geo_plot(geo_segment(geo_xy(0, 0), geo_xy(10, -10:10)))
#'
geo_segment <- function(start = geo_xy(), end = geo_xy(), srid = 0) {
  result <- new_geovctrs_segment(
    vec_recycle_common(
      start = vec_cast(start, geo_xy()),
      end = vec_cast(end, geo_xy()),
      srid = as_geo_srid(srid)
    )
  )

  result
}

#' S3 details for geovctrs_segment
#'
#' @param x A (possibly) [geo_segment()]
#' @inheritParams new_geovctrs_xy
#'
#' @export
#'
new_geovctrs_segment <- function(x = list(start = geo_xy(), end = geo_xy(), srid = integer())) {
  vec_assert(x$start, geo_xy())
  vec_assert(x$end, geo_xy())
  new_rcrd(x, class = c("geovctrs_segment", "geovctr"))
}

#' @export
#' @rdname new_geovctrs_segment
is_geovctrs_segment <- function(x) {
  inherits(x, "geovctrs_segment")
}

#' @export
#' @rdname new_geovctrs_segment
validate_geovctrs_segment <- function(x) {
  abort("not implemented")
}

#' @export
vec_ptype_abbr.geovctrs_segment <- function(x, ...) {
  "segment"
}

#' @export
format.geovctrs_segment <- function(x, ..., col = FALSE) {
  if (length(x) == 0) {
    return(character(0))
  }

  paste0(
    maybe_blue(
      "(",
      format(field(field(x, "start"), "x"), trim = TRUE, ...),
      " ",
      format(field(field(x, "start"), "y"), trim = TRUE, ...),
      col = col
    ),
    maybe_grey(if(use_utf8()) cli::symbol$arrow_right else cli::symbol$em_dash, col = col),
    maybe_blue(
      format(field(field(x, "end"), "x"), trim = TRUE, ...),
      " ",
      format(field(field(x, "end"), "y"), trim = TRUE, ...),
      ")",
      col = col
    )
  )
}

#' @export
print.geovctrs_segment <- function(x, ...) {
  obj_print_header(x, ...)
  print_default_colour(format(x, ..., col = FALSE), format(x, ..., col = TRUE))
  obj_print_footer(x, ...)
  invisible(x)
}

# dyamically exported in zzz.R
pillar_shaft.geovctrs_segment <- function(x, ...) {
  pillar::new_pillar_shaft_simple(format(x, col = TRUE))
}

#' @export
#' @importFrom tibble as_tibble
as_tibble.geovctrs_segment <- function(x, ...) {
  as_tibble(vec_data(x), ...)
}

#' @export
#' @importFrom tibble as_tibble
as.data.frame.geovctrs_segment <- function(x, ...) {
  as.data.frame(as_tibble.geovctrs_segment(x, ...))
}

# -------- casting ----------

#' @export
#' @rdname new_geovctrs_segment
as_geo_segment <- function(x, ...) {
  UseMethod("as_geo_segment")
}

#' @export
#' @rdname new_geovctrs_segment
as_geo_segment.default <- function(x, ...) {
  vec_cast(x, geo_segment())
}

#' @method vec_cast geovctrs_segment
#' @export
#' @export vec_cast.geovctrs_segment
#' @rdname new_geovctrs_segment
vec_cast.geovctrs_segment <- function(x, to, ...) {
  UseMethod("vec_cast.geovctrs_segment")
}

#' @method vec_cast.geovctrs_segment default
#' @export
vec_cast.geovctrs_segment.default <- function(x, to, ...) {
  vec_default_cast(x, to)
}

#' @method vec_cast.geovctrs_segment geovctrs_segment
#' @export
vec_cast.geovctrs_segment.geovctrs_segment <- function(x, to, ...) {
  x
}

#' @method vec_cast.geovctrs_segment geovctrs_wkt
#' @export
vec_cast.geovctrs_segment.geovctrs_wkt <- function(x, to, ...) {
  geovctrs_cpp_convert(x, to)
}

#' @method vec_cast.geovctrs_segment geovctrs_wkb
#' @export
vec_cast.geovctrs_segment.geovctrs_wkb <- function(x, to, ...) {
  geovctrs_cpp_convert(x, to)
}

#' @method vec_cast.geovctrs_segment geovctrs_collection
#' @export
vec_cast.geovctrs_segment.geovctrs_collection <- function(x, to, ...) {
  geovctrs_cpp_convert(x, to)
}

# ------------- prototypes ------------

#' @method vec_ptype2 geovctrs_segment
#' @export
#' @export vec_ptype2.geovctrs_segment
#' @rdname new_geovctrs_segment
vec_ptype2.geovctrs_segment <- function(x, y, ...) {
  UseMethod("vec_ptype2.geovctrs_segment", y)
}

#' @method vec_ptype2.geovctrs_segment default
#' @export
vec_ptype2.geovctrs_segment.default <- function(x, y, ..., x_arg = "x", y_arg = "y") {
  vec_default_ptype2(x, y, x_arg = x_arg, y_arg = y_arg) # nocov
}

#' @method vec_ptype2.geovctrs_segment geovctrs_segment
#' @export
vec_ptype2.geovctrs_segment.geovctrs_segment <- function(x, y, ..., x_arg = "x", y_arg = "y") {
  geo_segment()
}

#' @method vec_ptype2.geovctrs_segment geovctrs_wkt
#' @export
vec_ptype2.geovctrs_segment.geovctrs_wkt <- function(x, y, ..., x_arg = "x", y_arg = "y") {
  geo_wkt()
}

#' @method vec_ptype2.geovctrs_segment geovctrs_wkb
#' @export
vec_ptype2.geovctrs_segment.geovctrs_wkb <- function(x, y, ..., x_arg = "x", y_arg = "y") {
  geo_wkb()
}

#' @method vec_ptype2.geovctrs_segment geovctrs_collection
#' @export
vec_ptype2.geovctrs_segment.geovctrs_collection <- function(x, y, ..., x_arg = "x", y_arg = "y") {
  geo_collection()
}
