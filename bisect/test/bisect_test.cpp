#include <gtest/gtest.h>
#include "application.h"

namespace{

TEST(Sum, ErroCase) {
  const int result = sum(23,4);
  EXPECT_EQ(result, 27);
}
}

