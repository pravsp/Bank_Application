load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "banking-lib",
    srcs = glob(["**/*.cc"]),
    hdrs = glob(["**/include/*.h"]),
    visibility = ["//visibility:public"],
    deps = [
        "//src/utilities:banking-lib-utilities",
    ]
)