load("@rules_cc//cc:defs.bzl", "cc_test")
cc_test(
    name = "utilities_tests",
    srcs = glob(["**/*.cc"]),
    deps = [
        "//src/banking_utils:bank-utils",
        "@googletest//:gtest_main",
    ],
    copts = ["-Isrc/banking_utils/include"],
)