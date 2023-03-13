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

TEST(Product, ProductOfNegativeValues) {
  const int result = product(-10,-15);
  EXPECT_EQ(result, 150);
}

TEST(Product, ProductOfPositiveValues) {
  const int result = product(3,12);
  EXPECT_EQ(result, 36);
}