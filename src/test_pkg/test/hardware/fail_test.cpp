#include <gtest/gtest.h>

TEST(HardwareSuite, ThisShouldBeSkipped) {
  // If the CI runs this, it will fail, telling us the filter is broken.
  EXPECT_TRUE(false); 
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}