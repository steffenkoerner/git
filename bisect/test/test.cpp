#include <gtest/gtest.h>
#include "application.h"

TEST(Sum, AdditionOfPositiveValues) {

  const int result = sum(3,4);
  EXPECT_EQ(result, 7);
}

TEST(Sum, AdditionOfNegativeValues) {

  const int result = sum(-1,-5);
  EXPECT_EQ(result, -6);
}