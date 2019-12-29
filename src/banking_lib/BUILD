load("@rules_cc//cc:defs.bzl", "cc_library")


cc_library(
    name = "banking-oper",
    srcs = glob(["**/*.cc"]),
    hdrs = glob(["**/include/*.h"]),
    visibility = ["//visibility:public"],
    deps = [
        "//src/banking_utils:bank-utils",
    ],
    copts = ["-Isrc/banking_utils/include"]
)