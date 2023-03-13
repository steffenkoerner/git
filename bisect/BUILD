cc_library(
    name = "application",
    srcs = ["src/application.cpp"],
    hdrs = ["src/application.h"],
    strip_include_prefix ="src/",
)

cc_test(
  name = "bisect_test",
  srcs = glob(["test/**"]),
  deps = ["@gtest//:gtest",
        "@gtest//:gtest_main",
        ":application",
        ],
)