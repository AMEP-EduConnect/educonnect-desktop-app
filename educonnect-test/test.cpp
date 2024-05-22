#include "pch.h"

TEST(TestCI, GivenNothing_WhenDeployment_ThenPass) {
	//Given
	EXPECT_EQ(1, 1);
	//When

	//Then
	EXPECT_TRUE(true);
}

TEST(TestCI, GivenNothing_WhenDeployment_ThenNotPass) {
	//Given
	EXPECT_EQ(1, 0);
	//When

	//Then
	EXPECT_TRUE(false);
}
