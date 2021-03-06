
#' Plot geometry vectors
#'
#' Currently, only geometries of the same type can be plotted in the same
#' plot call (geometries are promoted to mutli-geometries if needed).
#'
#' @inheritParams geo_bbox
#' @param ... Passed to plotting functions for features: [graphics::points()]
#'   for point and multipoint geometries, [graphics::lines()] for linestring
#'   and multilinestring geometries, and [graphics::polypath()] for polygon
#'   and multipolygon geometries.
#' @param bbox The limits of the plot. Defaults to `geo_bbox(x, finite = TRUE)`.
#' @param asp,xlab,ylab Passed to [graphics::plot()]
#'
#' @return `x`, invisibly.
#' @export
#'
#' @examples
#' geo_plot(geo_wkt("POINT (10 40)"))
#' geo_plot(geo_wkt("LINESTRING (30 10, 10 30, 40 40)"))
#' geo_plot(geo_wkt("MULTIPOINT ((10 40), (40 30))"))
#' geo_plot(geo_wkt("MULTILINESTRING ((10 10, 20 20, 10 40), (40 40, 30 30, 40 20, 30 10))"))
#' geo_plot(geo_wkt("POLYGON ((30 10, 10 30, 40 40, 30 10))"))
#' geo_plot(
#'   geo_wkt(
#'     "MULTIPOLYGON (((40 40, 20 45, 45 30, 40 40)),
#'       ((20 35, 10 30, 10 10, 30 5, 45 20, 20 35), (30 20, 20 15, 20 25, 30 20)))"
#'   ),
#'   col = "grey90"
#' )
#'
#' # can also plot data frames that have exactly one geovctr column
#' prev_pal <- palette(grey.colors(10))
#' geo_plot(geo_nc, col = cut(BIR79, 10))
#'
#' # restore initial palette
#' palette(prev_pal)
#'
geo_plot <- function(x, ..., asp = 1, bbox = geo_bbox(x, finite = TRUE), xlab = "", ylab = "") {
  bbox <- as_geo_rect(bbox)
  xlim <- c(field(bbox, "xmin"), field(bbox, "xmax"))
  ylim <- c(field(bbox, "ymin"), field(bbox, "ymax"))

  graphics::plot(
    numeric(0),
    numeric(0),
    xlim = xlim,
    ylim = ylim,
    xlab = xlab,
    ylab = ylab,
    asp = asp
  )

  geo_plot_add(x, ...)
  invisible(x)
}

#' @rdname geo_plot
#' @export
geo_plot_add <- function(x, ...) {
  UseMethod("geo_plot_add")
}

#' @rdname geo_plot
#' @export
geo_plot_add.default <- function(x, ...) {
  geo_plot_add(as_geovctr(x), ...)
  invisible(x)
}

#' @rdname geo_plot
#' @export
geo_plot_add.geovctr <- function(x, ...) {
  geo_plot_add(as_geo_collection(x), ...)
  invisible(x)
}

#' @rdname geo_plot
#' @export
geo_plot_add.data.frame <- function(x, ...) {
  # evaluate the dots
  dots <- rlang::quos(...)
  dots_eval <- lapply(dots, rlang::eval_tidy, data = x)
  dots_tbl <- vec_recycle_common(!!!dots_eval, .size = nrow(x))

  # plot the features
  rlang::exec(geo_plot_add, as_geovctr(x), !!!dots_tbl)

  # return the input
  invisible(x)
}

#' @rdname geo_plot
#' @export
geo_plot_add.NULL <- function(x, ...) {
  invisible(x)
}

#' @rdname geo_plot
#' @export
geo_plot_add.geovctrs_xy <- function(x, ...) {
  graphics::points(field(x, "x"), field(x, "y"), ...)
  invisible(x)
}

#' @rdname geo_plot
#' @export
geo_plot_add.geovctrs_segment <- function(x, ...) {
  start <- field(x, "start")
  end <- field(x, "end")

  graphics::segments(
    field(start, "x"), field(start, "y"),
    field(end, "x"), field(end, "y"),
    ...
  )

  invisible(x)
}

#' @rdname geo_plot
#' @export
geo_plot_add.geovctrs_rect <- function(x, ...) {
  graphics::rect(
    field(x, "xmin"), field(x, "ymin"),
    field(x, "xmax"), field(x, "ymax"),
    ...
  )
  invisible(x)
}

#' @rdname geo_plot
#' @export
geo_plot_add.geovctrs_collection <- function(x, ...) {
  features <- field(x, "feature")

  # evaluate dots, wrap scalar types in a list(), and vectorize
  dots <- rlang::list2(...)
  is_scalar <- !vapply(dots, vec_is, logical(1))
  dots[is_scalar] <- lapply(dots[is_scalar], list)
  dots_tbl <- vec_recycle_common(!!!dots, .size = length(features))

  # using for() because the user interupt is respected
  for (i in seq_along(features)) {
    dots_item <- lapply(dots_tbl, "[[", i)
    rlang::exec(geo_plot_add, features[[i]], !!!dots_item)
  }
  invisible(x)
}

#' @export
geo_plot_add.geovctrs_point <- function(x, ...) {
  xy <- field(x, "xy")
  graphics::points(field(xy, "x"), field(xy, "y"), ...)
  invisible(x)
}

#' @export
geo_plot_add.geovctrs_linestring <- function(x, ...) {
  xy <- field(x, "xy")
  graphics::lines(field(xy, "x"), field(xy, "y"), ...)
  invisible(x)
}

#' @export
geo_plot_add.geovctrs_polygon <- function(x, ..., rule = "evenodd") {
  # have to do one feature at a time because the "holes in polygons" problem
  xy <- separate_groups_with_na(field(x, "xy"), field(x, "ring"))

  # graphics::polypath doesn't do zero-length coords
  if (vec_size(xy) > 0) {
    graphics::polypath(field(xy, "x"), field(xy, "y"), ..., rule = rule)
  }

  invisible(x)
}

#' @export
geo_plot_add.geovctrs_multipoint <- function(x, ...) {
  xy <- field(x, "xy")
  graphics::points(field(xy, "x"), field(xy, "y"), ...)
  invisible(x)
}

#' @export
geo_plot_add.geovctrs_multilinestring <- function(x, ...) {
  xy <- separate_groups_with_na(
    field(x, "xy"),
    field(x, "part")
  )
  graphics::lines(field(xy, "x"), field(xy, "y"), ...)
  invisible(x)
}

#' @export
geo_plot_add.geovctrs_multipolygon <- function(x, ..., rule = "evenodd") {
  # have to do one part at a time because the "holes in polygons" problem
  crds <- tibble::tibble(xy = field(x, "xy"), ring = field(x, "ring"))
  for (crds_feat in split(crds, field(x, "part"))) {
    xy_part <- separate_groups_with_na(crds_feat$xy, crds_feat$ring)
    if (vec_size(xy_part) > 0) {
      graphics::polypath(field(xy_part, "x"), field(xy_part, "y"), ..., rule = rule)
    }
  }
  invisible(x)
}

separate_groups_with_na <- function(x, groups) {
  if (length(x) == 0) {
    return(x)
  }

  if (is.factor(groups)) {
    groups <- as.integer(unclass(groups))
  }

  n_groups <- n_distinct(groups)
  lengths <- rle(groups)$lengths

  start_i <- c(0, cumsum(lengths[-length(lengths)]))
  new_start_i <- start_i + seq_along(lengths) - 1
  indices <- Map(function(x, y) c(x + seq_len(y), NA), start_i, lengths)
  x[vec_c(!!!indices)][-(length(x) + n_groups)]
}

#' @importFrom graphics plot
#' @export
plot.geovctr <- function(x, ...) {
  geo_plot(x, ...)
}
