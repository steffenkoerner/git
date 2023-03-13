#include <gtest/gtest.h>
#include "application.h"

TEST(Sum, AdditionOfPositiveValues) {

  const int result = sum(3,4);
  EXPECT_EQ(result, 7);
}