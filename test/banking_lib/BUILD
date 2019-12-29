load("@rules_cc//cc:defs.bzl", "cc_test")
cc_test(
    name = "bank_oper_test",
    srcs = glob(["**/*.cc"]),
    deps = [
        "//src/banking_utils:bank-utils",
        "//src/banking_lib:banking-oper",
        "@googletest//:gtest_main",
    ],
    copts = ["-Isrc/banking_utils/include", "-Isrc/banking_lib/include"],
)