% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/geo-collection.R
\name{geo_collection}
\alias{geo_collection}
\alias{geo_point}
\alias{geo_linestring}
\alias{geo_polygon}
\alias{geo_multipoint}
\alias{geo_multilinestring}
\alias{geo_multipolygon}
\title{Geometry constructors}
\usage{
geo_collection(feature = list(), srid = 0)

geo_point(xy, srid = 0)

geo_linestring(xy, srid = 0)

geo_polygon(xy, ring = 1L, srid = 0)

geo_multipoint(feature, srid = 0)

geo_multilinestring(feature, srid = 0)

geo_multipolygon(feature, srid = 0)
}
\arguments{
\item{feature}{A \code{\link[=geo_collection]{geo_collection()}} of one or more features.
for multi geometries, this must be a collection that only contains
that type (e.g., multipolygons can only be composed of polygons).}

\item{srid}{A spatial reference identifier, coerced to
an integer by \code{\link[=as_geo_srid]{as_geo_srid()}}. These identifiers can
and should be managed outside of geovctrs except for
0, which is interpreted as "not set".}

\item{xy}{A \code{\link[=geo_xy]{geo_xy()}} of coordinates}

\item{ring}{A vector whose unique values separate rings. Row order
matters: the first value encountered will identify the outer ring.}
}
\value{
A \code{\link[=new_geovctrs_collection]{new_geovctrs_collection()}} of length 1.
}
\description{
A \code{\link[=geo_collection]{geo_collection()}} is an in-memory R-native format that can store most
geometries. It is used to power \code{\link[=geo_plot]{geo_plot()}} in addition to providing
constructors for geometries from data frames (possibly using
\code{\link[dplyr:group_by]{dplyr::group_by()}} and \code{\link[dplyr:summarise]{dplyr::summarise()}}). Collections contain zero
or more objects of type \code{\link[=geo_point]{geo_point()}}, \code{\link[=geo_linestring]{geo_linestring()}}, \code{\link[=geo_polygon]{geo_polygon()}},
\code{\link[=geo_multipoint]{geo_multipoint()}}, \code{\link[=geo_multilinestring]{geo_multilinestring()}}, and/or
\code{\link[=geo_multipolygon]{geo_multipolygon()}}.
}
\examples{
# geo_point() and family all return a geo_collection() of length 1
c(geo_point(geo_xy(0, 1)), geo_point(geo_xy(1, 2)))

# linestring
geo_linestring(geo_xy(1:5, 2:6))

# a polygon
geo_polygon(geo_xy(c(0, 10, 0, 0), c(0, 0, 10, 0)))

# polygon with a hole
poly_hole <- geo_polygon(
  geo_xy(
    c(35, 45, 15, 10, 35, 20, 35, 30, 20),
    c(10, 45, 40, 20, 10, 30, 35, 20, 30)
  ),
  ring = c(1, 1, 1, 1, 1, 2, 2, 2, 2)
)

# multipoint
geo_multipoint(
  c(geo_point(geo_xy(10, 30)), geo_point(geo_xy(12, 11)))
)

# multilinestring
geo_multilinestring(
  c(
    geo_linestring(geo_xy(0:1, 0:1)),
    geo_linestring(geo_xy(c(12, 30), c(11, 10)))
  )
)

# multipolygon
geo_multipolygon(
  geo_polygon(geo_xy(c(0, 10, 0, 0), c(0, 0, 10, 0)))
)

# nested geo_collection()
c(geo_point(geo_xy(0, 1)), geo_collection(geo_point(geo_xy(1, 2))))

}
