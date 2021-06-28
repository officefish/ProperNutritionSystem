#include "pch.h"
#include "Meal.h"
#include <type_traits>

using namespace meal;

/* Apple Tests */

TEST(MealVitamins_Tests, Apple_Vitamins_Mask) {

	meal::MealVitamins vitamins{ 72075323932480274 };
	EXPECT_EQ(vitamins.getA(), 2);
	EXPECT_EQ(vitamins.getB1(), 1);
	EXPECT_EQ(vitamins.getB2(), 3);
	EXPECT_EQ(vitamins.getB3(), 1);
	EXPECT_EQ(vitamins.getB5(), 1);
	EXPECT_EQ(vitamins.getB6(), 1);
	EXPECT_EQ(vitamins.getB7(), 0);
	EXPECT_EQ(vitamins.getB9(), 1);
	EXPECT_EQ(vitamins.getB12(), 0);
	EXPECT_EQ(vitamins.getC(), 2);
	EXPECT_EQ(vitamins.getD(), 0);
	EXPECT_EQ(vitamins.getE(), 1);
	EXPECT_EQ(vitamins.getK(), 0);
	EXPECT_EQ(vitamins.getN(), 0);
	EXPECT_EQ(vitamins.getP(), 1);
	EXPECT_EQ(vitamins.getU(), 0);
}

TEST(MealVitamins_Tests, Apple_Vitamins_Valid_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14010101, 0, 100);
	if (ptr) status = (*ptr).validateVitamins(72075323932480274);
	EXPECT_EQ(status, true);
}

/* Pear Tests */
TEST(MealVitamins_Tests, Pear_Vitamins_Mask) {

	meal::MealVitamins vitamins{ 72374391632101649 };
	EXPECT_EQ(vitamins.getA(), 1);
	EXPECT_EQ(vitamins.getB1(), 1);
	EXPECT_EQ(vitamins.getB2(), 1);
	EXPECT_EQ(vitamins.getB3(), 0);
	EXPECT_EQ(vitamins.getB5(), 1);
	EXPECT_EQ(vitamins.getB6(), 1);
	EXPECT_EQ(vitamins.getB7(), 0);
	EXPECT_EQ(vitamins.getB9(), 3);
	EXPECT_EQ(vitamins.getB12(), 0);
	EXPECT_EQ(vitamins.getC(), 2);
	EXPECT_EQ(vitamins.getD(), 0);
	EXPECT_EQ(vitamins.getE(), 2);
	EXPECT_EQ(vitamins.getK(), 1);
	EXPECT_EQ(vitamins.getN(), 0);
	EXPECT_EQ(vitamins.getP(), 1);
	EXPECT_EQ(vitamins.getU(), 0);
}

TEST(MealVitamins_Tests, Pear_Vitamins_Valid_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14010102, 0, 100);
	if (ptr) status = (*ptr).validateVitamins(72374391632101649);
	EXPECT_EQ(status, true);
}

/* Plum Tests */
TEST(MealVitamins_Tests, Plum_Vitamins_Mask) {

	meal::MealVitamins vitamins{ 72110508304568593 };
	EXPECT_EQ(vitamins.getA(), 1);
	EXPECT_EQ(vitamins.getB1(), 1);
	EXPECT_EQ(vitamins.getB2(), 1);
	EXPECT_EQ(vitamins.getB3(), 1);
	EXPECT_EQ(vitamins.getB5(), 1);
	EXPECT_EQ(vitamins.getB6(), 1);
	EXPECT_EQ(vitamins.getB7(), 0);
	EXPECT_EQ(vitamins.getB9(), 1);
	EXPECT_EQ(vitamins.getB12(), 0);
	EXPECT_EQ(vitamins.getC(), 2);
	EXPECT_EQ(vitamins.getD(), 0);
	EXPECT_EQ(vitamins.getE(), 3);
	EXPECT_EQ(vitamins.getK(), 0);
	EXPECT_EQ(vitamins.getN(), 0);
	EXPECT_EQ(vitamins.getP(), 1);
	EXPECT_EQ(vitamins.getU(), 0);
}

TEST(MealVitamins_Tests, Plum_Vitamins_Valid_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14010103, 0, 100);
	if (ptr) status = (*ptr).validateVitamins(72110508304568593);
	EXPECT_EQ(status, true);
}


/* Orange Tests */

TEST(MealVitamins_Tests, Orange_Vitamins_Mask) {

	meal::MealVitamins vitamins{ 72075323931365649 };
	EXPECT_EQ(vitamins.getA(), 1);
	EXPECT_EQ(vitamins.getB1(), 1);
	EXPECT_EQ(vitamins.getB2(), 1);
	EXPECT_EQ(vitamins.getB3(), 1);

	EXPECT_EQ(vitamins.getB5(), 0);
	EXPECT_EQ(vitamins.getB6(), 0);
	EXPECT_EQ(vitamins.getB7(), 0);
	EXPECT_EQ(vitamins.getB9(), 1);

	EXPECT_EQ(vitamins.getB12(), 0);
	EXPECT_EQ(vitamins.getC(), 2);
	EXPECT_EQ(vitamins.getD(), 0);
	EXPECT_EQ(vitamins.getE(), 1);

	EXPECT_EQ(vitamins.getK(), 0);
	EXPECT_EQ(vitamins.getN(), 0);
	EXPECT_EQ(vitamins.getP(), 1);
	EXPECT_EQ(vitamins.getU(), 0);
}

TEST(MealVitamins_Tests, Orange_Vitamins_Valid_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14020101, 0, 100);
	if (ptr) status = (*ptr).validateVitamins(72075323931365649);
	EXPECT_EQ(status, true);
}

/* Granate Tests */

TEST(MealVitamins_Tests, Granate_Vitamins_Mask) {

	meal::MealVitamins vitamins{ 72638278180868369 };
	EXPECT_EQ(vitamins.getA(), 1);
	EXPECT_EQ(vitamins.getB1(), 1);
	EXPECT_EQ(vitamins.getB2(), 1);
	EXPECT_EQ(vitamins.getB3(), 1);

	EXPECT_EQ(vitamins.getB5(), 1);
	EXPECT_EQ(vitamins.getB6(), 1);
	EXPECT_EQ(vitamins.getB7(), 0);
	EXPECT_EQ(vitamins.getB9(), 1);

	EXPECT_EQ(vitamins.getB12(), 1);
	EXPECT_EQ(vitamins.getC(), 2);
	EXPECT_EQ(vitamins.getD(), 0);
	EXPECT_EQ(vitamins.getE(), 1);

	EXPECT_EQ(vitamins.getK(), 2);
	EXPECT_EQ(vitamins.getN(), 0);
	EXPECT_EQ(vitamins.getP(), 1);
	EXPECT_EQ(vitamins.getU(), 0);
}

TEST(MealVitamins_Tests, Granate_Vitamins_Valid_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14020102, 0, 100);
	if (ptr) status = (*ptr).validateVitamins(72638278180868369);
	EXPECT_EQ(status, true);
}


/* Persimmon Tests */

TEST(MealVitamins_Tests, Persimmon_Vitamins_Mask) {

	meal::MealVitamins vitamins{ 72356730189844752 };
	EXPECT_EQ(vitamins.getA(), 0);
	EXPECT_EQ(vitamins.getB1(), 1);
	EXPECT_EQ(vitamins.getB2(), 1);
	EXPECT_EQ(vitamins.getB3(), 1);

	EXPECT_EQ(vitamins.getB5(), 3);
	EXPECT_EQ(vitamins.getB6(), 1);
	EXPECT_EQ(vitamins.getB7(), 0);
	EXPECT_EQ(vitamins.getB9(), 1);

	EXPECT_EQ(vitamins.getB12(), 0);
	EXPECT_EQ(vitamins.getC(), 1);
	EXPECT_EQ(vitamins.getD(), 0);
	EXPECT_EQ(vitamins.getE(), 1);

	EXPECT_EQ(vitamins.getK(), 1);
	EXPECT_EQ(vitamins.getN(), 0);
	EXPECT_EQ(vitamins.getP(), 1);
	EXPECT_EQ(vitamins.getU(), 0);
}

TEST(MealVitamins_Tests, Persimmon_Vitamins_Valid_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14020103, 0, 100);
	if (ptr) status = (*ptr).validateVitamins(72356730189844752);
	EXPECT_EQ(status, true);
}


