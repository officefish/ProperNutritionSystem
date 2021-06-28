#include "pch.h"
#include "Meal.h"

using namespace meal;

TEST(Meal_Elements_Tests, Nutrients_Is_Not_Trivially_Constructible) {
	bool status = std::is_trivially_constructible<Nutrients, int16_t, int16_t, int16_t>::value;
	EXPECT_EQ(status, false);
}

TEST(Meal_Elements_Tests, Nutrients_Is_Nothrow_Constructible) {
	bool status = std::is_nothrow_constructible<Nutrients, int16_t, int16_t, int16_t>::value;
	EXPECT_EQ(status, true);
}

TEST(Meal_Elements_Tests, Nutrients_Is_Not_Trivially_Copy_Constructible) {
	bool status = std::is_trivially_copy_constructible<Nutrients>::value;
	EXPECT_EQ(status, false);
}

TEST(Meal_Elements_Tests, Nutrients_Is_Nothrow_Copy_Constructible) {
	bool status = std::is_nothrow_copy_constructible<Nutrients>::value;
	EXPECT_EQ(status, true);
}

