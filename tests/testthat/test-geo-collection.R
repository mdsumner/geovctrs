
test_that("geo_collection class works", {
  collection <- geo_collection(list(geo_linestring(geo_xy(c(0, 1, 6), c(0, 2, 4)))))
  expect_output(print(collection), "geo_collection")
  expect_output(print(tibble(collection)), "geo_clctn")
  expect_is(collection, "geo_collection")
  expect_true(is_geo_collection(collection))
  expect_true(vec_is(collection))

  # output with  nexted collection
  expect_output(print(geo_collection(list(collection))), "\\[1\\]\\s*<geo_collection")
})