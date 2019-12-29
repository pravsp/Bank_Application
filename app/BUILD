load("@rules_cc//cc:defs.bzl", "cc_binary")


cc_binary(
    name = "banking-app",
    srcs = glob(["**/*.cc","**/*.h"]),
    deps = [
        "//src/banking_lib:banking-oper",
        "//src/banking_utils:bank-utils",
        "//dist:jsoncpp",
    ],
    copts = ["-Isrc/banking_lib/include"],
)