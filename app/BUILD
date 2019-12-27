load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "banking-app-lib",
    srcs = ["bank_interface.cc"],
    hdrs = ["bank_interface.h"],
    visibility = ["//visibility:public"],
    deps = [
        "//src/lib:banking-lib",
    ]
)

cc_binary(
    name = "banking-app",
    srcs = ["banking_app.cc"],
    deps = [
        "//src/lib:banking-lib",
        "//src/main:banking-app-lib",
    ],
)