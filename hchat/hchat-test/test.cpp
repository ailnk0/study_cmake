#include <gtest/gtest.h>

#include "hchat.h"

TEST(hchat_test, getHello) {
  // given
  hchat::hchat h;

  // when
  auto result = h.getHello();

  // then
  EXPECT_EQ("Hello, World!", result);
}
