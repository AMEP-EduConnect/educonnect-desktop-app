#pragma once
#include "gtest/gtest.h"

TEST(TestCI, GivenNothing_WhenDeployment_ThenPass) {
	//Given
	EXPECT_EQ(1, 1);
	//When

	//Then
	EXPECT_TRUE(true);
}

TEST(TestCI, GivenNothing_WhenDeployment_ThenNotPass) {
	//Given
	EXPECT_EQ(1, 1);
	//When

	//Then
	EXPECT_TRUE(true);
}
