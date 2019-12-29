load("@rules_cc//cc:defs.bzl", "cc_library")


cc_library(
    name = "bank-utils",
    srcs = glob(["**/*.cc"]),
    hdrs = glob(["**/include/*.h"]),
    visibility = ["//visibility:public"],
    deps = [
        "//dist:jsoncpp",
    ],
    copts = ["-Idist","-Isrc/banking_utils/include"],
    
)