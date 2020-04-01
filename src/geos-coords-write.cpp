
#include "geos-coords-write.h"
using namespace Rcpp;

GEOSCoordSequence* seq_from_xy(GEOSContextHandle_t context, List xy, int offset, size_t size) {
  NumericVector x = xy["x"];
  NumericVector y = xy["y"];

  GEOSCoordSequence* seq = GEOSCoordSeq_create_r(context, size, 2);
  for (size_t i=0; i<size; i++) {
    GEOSCoordSeq_setX_r(context, seq, i, x[offset + i]);
    GEOSCoordSeq_setY_r(context, seq, i, y[offset + i]);
  }

  return seq;
}

GEOSGeometry* feature_from_geo_coord(GEOSContextHandle_t context, List feature) {
  if (Rf_inherits(feature, "geo_point")) {
    return point_from_geo_coord(context, feature);

  } else if(Rf_inherits(feature, "geo_linestring")) {
    return linestring_from_geo_coord(context, feature);

  } else if(Rf_inherits(feature, "geo_polygon")) {
    return polygon_from_geo_coord(context, feature);

  } else if(Rf_inherits(feature, "geo_multipoint")) {
    return multipoint_from_geo_coord(context, feature);

  } else if(Rf_inherits(feature, "geo_multilinestring")) {
    return multilinestring_from_geo_coord(context, feature);

  } else if(Rf_inherits(feature, "geo_multipolygon")) {
    return multipolygon_from_geo_coord(context, feature);

  } else if(Rf_inherits(feature, "geo_collection")) {
    return geometrycollection_from_geo_coord(context, feature);

  } else {
    stop("Can only convert point, linestring, polygon, and multi- variants from a geo_coord");
  }
}

GEOSGeometry* point_from_geo_coord(GEOSContextHandle_t context, List feature) {
  List xy = feature["xy"];
  NumericVector x = xy["x"];
  if (x.size() == 0) {
    return GEOSGeom_createEmptyPoint_r(context);
  }

  GEOSCoordSequence* seq = seq_from_xy(context, xy, 0, x.size());
  return GEOSGeom_createPoint_r(context, seq);
}

GEOSGeometry* linestring_from_geo_coord(GEOSContextHandle_t context, List feature) {
  List xy = feature["xy"];
  NumericVector x = xy["x"];
  if (x.size() == 0) {
    return GEOSGeom_createEmptyLineString_r(context);
  }

  GEOSCoordSequence* seq = seq_from_xy(context, xy, 0, x.size());
  return GEOSGeom_createLineString_r(context, seq);
}

GEOSGeometry* polygon_from_geo_coord(GEOSContextHandle_t context, List feature) {
  List xy = feature["xy"];
  NumericVector ring = feature["ring"];
  if (ring.size() == 0) {
    return GEOSGeom_createEmptyPolygon_r(context);
  }

  // one pass through to find the number of rings
  int nRings = 1;
  for (size_t i=1; i < ring.size(); i++) {
    if (ring[i] != ring[i - 1]) {
      nRings++;
    }
  }

  // one pass through to find their lengths
  NumericVector ringLengths(nRings);
  int iRing = 0;
  size_t lastRing = 0;
  for (size_t i=1; i < ring.size(); i++) {
    if (ring[i] != ring[i - 1]) {
      ringLengths[iRing] = i - lastRing;
      lastRing = i;
      iRing++;
    }
  }

  ringLengths[iRing] = ring.size() - lastRing;

  // generate outer shell
  GEOSCoordSequence* shellSeq = seq_from_xy(context, xy, 0, ringLengths[0]);
  GEOSGeometry* shell = GEOSGeom_createLinearRing_r(context, shellSeq);

  // generate holes
  GEOSGeometry* holes[ringLengths.size() - 1];
  size_t offset = ringLengths[0];
  for (int i=1; i < ringLengths.size(); i++) {
    GEOSCoordSequence* holeSeq = seq_from_xy(context, xy, offset, ringLengths[i]);
    holes[i - 1] = GEOSGeom_createLinearRing_r(context, holeSeq);
    offset += ringLengths[i];
  }

  // generate polygon
  return GEOSGeom_createPolygon_r(context, shell, holes, ringLengths.size() - 1);
}

GEOSGeometry* multipoint_from_geo_coord(GEOSContextHandle_t context, List feature) {
  stop("Can only convert point");
}

GEOSGeometry* multilinestring_from_geo_coord(GEOSContextHandle_t context, List feature) {
  stop("Can only convert point");
}

GEOSGeometry* multipolygon_from_geo_coord(GEOSContextHandle_t context, List feature) {
  stop("Can only convert point");
}

GEOSGeometry* geometrycollection_from_geo_coord(GEOSContextHandle_t context, List feature) {
  stop("Can only convert point");
}
