#include "pch.h"
#include "Meal.h"
#include <type_traits>

using namespace meal;

/* Apple Tests */

TEST(MealMinerals_Tests, Apple_Minerals_Mask) {

	meal::MealMinerals minerals{ 1229767540789547265 };
	EXPECT_EQ(minerals.getK(), 1);
	EXPECT_EQ(minerals.getCl(), 0);
	EXPECT_EQ(minerals.getNa(), 1);
	EXPECT_EQ(minerals.getCa(), 1);
	EXPECT_EQ(minerals.getP(), 1);
	EXPECT_EQ(minerals.getMg(), 1);
	EXPECT_EQ(minerals.getZn(), 1);
	EXPECT_EQ(minerals.getFe(), 1);
	EXPECT_EQ(minerals.getMn(), 0);
	EXPECT_EQ(minerals.getCu(), 1);
	EXPECT_EQ(minerals.getI(), 3);
	EXPECT_EQ(minerals.getSe(), 0);
	EXPECT_EQ(minerals.getMo(), 1);
	EXPECT_EQ(minerals.getS(), 1);
	EXPECT_EQ(minerals.getCr(), 1);
	EXPECT_EQ(minerals.getF(), 1);
}

TEST(MealMinerals_Tests, Apple_Minerals_Valid_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14010101, 0, 100);
	if (ptr) status = (*ptr).validateMinerals(1229767540789547265);
	EXPECT_EQ(status, true);
}

/* Pear Tests */

TEST(MealMinerals_Tests, Pear_Minerals_Mask) {

	meal::MealMinerals minerals{ 1152941369116922113 };
	EXPECT_EQ(minerals.getK(), 1);
	EXPECT_EQ(minerals.getCl(), 0);
	EXPECT_EQ(minerals.getNa(), 1);
	EXPECT_EQ(minerals.getCa(), 1);
	EXPECT_EQ(minerals.getP(), 1);
	EXPECT_EQ(minerals.getMg(), 1);
	EXPECT_EQ(minerals.getZn(), 1);
	EXPECT_EQ(minerals.getFe(), 1);
	EXPECT_EQ(minerals.getMn(), 1);
	EXPECT_EQ(minerals.getCu(), 1);
	EXPECT_EQ(minerals.getI(), 2);
	EXPECT_EQ(minerals.getSe(), 1);
	EXPECT_EQ(minerals.getMo(), 0);
	EXPECT_EQ(minerals.getS(), 0);
	EXPECT_EQ(minerals.getCr(), 0);
	EXPECT_EQ(minerals.getF(), 1);
}

TEST(MealMinerals_Tests, Pear_Minerals_Valid_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14010102, 0, 100);
	if (ptr) status = (*ptr).validateMinerals(1152941369116922113);
	EXPECT_EQ(status, true);
}

/* Plum Tests */


TEST(MealMinerals_Tests, Plum_Minerals_Mask) {

	meal::MealMinerals minerals{ 1229766514577576210 };
	EXPECT_EQ(minerals.getK(), 2);
	EXPECT_EQ(minerals.getCl(), 1);
	EXPECT_EQ(minerals.getNa(), 1);
	EXPECT_EQ(minerals.getCa(), 1);
	EXPECT_EQ(minerals.getP(), 1);
	EXPECT_EQ(minerals.getMg(), 1);
	EXPECT_EQ(minerals.getZn(), 2);
	EXPECT_EQ(minerals.getFe(), 2);
	EXPECT_EQ(minerals.getMn(), 1);
	EXPECT_EQ(minerals.getCu(), 2);
	EXPECT_EQ(minerals.getI(), 2);
	EXPECT_EQ(minerals.getSe(), 0);
	EXPECT_EQ(minerals.getMo(), 1);
	EXPECT_EQ(minerals.getS(), 1);
	EXPECT_EQ(minerals.getCr(), 1);
	EXPECT_EQ(minerals.getF(), 1);
}

TEST(MealMinerals_Tests, Plum_Minerals_Valid_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14010103, 0, 100);
	if (ptr) status = (*ptr).validateMinerals(1229766514577576210);
	EXPECT_EQ(status, true);
}


/* Orange Tests */

TEST(MealMinerals_Tests, Orange_Minerals_Mask) {

	meal::MealMinerals minerals{ 1152921573596860674 };
	EXPECT_EQ(minerals.getK(), 2);
	EXPECT_EQ(minerals.getCl(), 0);
	EXPECT_EQ(minerals.getNa(), 1);
	EXPECT_EQ(minerals.getCa(), 1);
	EXPECT_EQ(minerals.getP(), 0);
	EXPECT_EQ(minerals.getMg(), 2);
	EXPECT_EQ(minerals.getZn(), 0);
	EXPECT_EQ(minerals.getFe(), 1);
	EXPECT_EQ(minerals.getMn(), 0);
	EXPECT_EQ(minerals.getCu(), 1);
	EXPECT_EQ(minerals.getI(), 0);
	EXPECT_EQ(minerals.getSe(), 0);
	EXPECT_EQ(minerals.getMo(), 0);
	EXPECT_EQ(minerals.getS(), 0);
	EXPECT_EQ(minerals.getCr(), 0);
	EXPECT_EQ(minerals.getF(), 1);
}

TEST(MealMinerals_Tests, Orange_Minerals_Valid_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14020101, 0, 100);
	if (ptr) status = (*ptr).validateMinerals(1152921573596860674);
	EXPECT_EQ(status, true);
}

/* Granate Tests */

TEST(MealMinerals_Tests, Granate_Minerals_Mask) {

	meal::MealMinerals minerals{ 1152921573596860674 };
	EXPECT_EQ(minerals.getK(), 2);
	EXPECT_EQ(minerals.getCl(), 0);
	EXPECT_EQ(minerals.getNa(), 1);
	EXPECT_EQ(minerals.getCa(), 1);
	EXPECT_EQ(minerals.getP(), 0);
	EXPECT_EQ(minerals.getMg(), 2);
	EXPECT_EQ(minerals.getZn(), 0);
	EXPECT_EQ(minerals.getFe(), 1);
	EXPECT_EQ(minerals.getMn(), 0);
	EXPECT_EQ(minerals.getCu(), 1);
	EXPECT_EQ(minerals.getI(), 0);
	EXPECT_EQ(minerals.getSe(), 0);
	EXPECT_EQ(minerals.getMo(), 0);
	EXPECT_EQ(minerals.getS(), 0);
	EXPECT_EQ(minerals.getCr(), 0);
	EXPECT_EQ(minerals.getF(), 1);
}

TEST(MealMinerals_Tests, Granate_Minerals_Valid_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14020102, 0, 100);
	if (ptr) status = (*ptr).validateMinerals(1152921573596860674);
	EXPECT_EQ(status, true);
}

/* Persimmon Tests */

TEST(MealMinerals_Tests, Persimmon_Minerals_Mask) {

	meal::MealMinerals minerals{ 1225280438131560705 };
	EXPECT_EQ(minerals.getK(), 1);
	EXPECT_EQ(minerals.getCl(), 0);
	EXPECT_EQ(minerals.getNa(), 1);
	EXPECT_EQ(minerals.getCa(), 1);
	EXPECT_EQ(minerals.getP(), 1);
	EXPECT_EQ(minerals.getMg(), 1);
	EXPECT_EQ(minerals.getZn(), 1);
	EXPECT_EQ(minerals.getFe(), 1);
	EXPECT_EQ(minerals.getMn(), 1);
	EXPECT_EQ(minerals.getCu(), 1);
	EXPECT_EQ(minerals.getI(), 2);
	EXPECT_EQ(minerals.getSe(), 1);
	EXPECT_EQ(minerals.getMo(), 1);
	EXPECT_EQ(minerals.getS(), 0);
	EXPECT_EQ(minerals.getCr(), 1);
	EXPECT_EQ(minerals.getF(), 1);
}

TEST(MealMinerals_Tests, Persimmon_Minerals_Valid_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14020103, 0, 100);
	if (ptr) status = (*ptr).validateMinerals(1225280438131560705);
	EXPECT_EQ(status, true);
}
