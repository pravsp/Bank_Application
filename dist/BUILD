load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "jsoncpp",
    srcs = glob(["**/src/*.cc"]),
    hdrs = glob(["**/json/*.h"]),
    visibility = ["//visibility:public"],
    
    alwayslink=1
)