#include "pch.h"
#include "Meal.h"
#include <type_traits>

using namespace meal;



/*	Apple Tests */

TEST(TasteQualities_Tests, Apple_Level_0_QualitiesMask) {
	meal::TasteQualities qualities{ 1056 };
	EXPECT_EQ(qualities.getSalty(), 0);
	EXPECT_EQ(qualities.getAcidic(), 0);
	EXPECT_EQ(qualities.getSugary(), 2);
	EXPECT_EQ(qualities.getBitter(), 0);
	EXPECT_EQ(qualities.getFatty(), 0);
	EXPECT_EQ(qualities.getStiff(), 1);
	EXPECT_EQ(qualities.getHarsh(), 0);
	EXPECT_EQ(qualities.getHot(), 0);
}

TEST(TasteQualities_Tests, Apple_Qualities_Valid_Level_0_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14010101, 0, 100);
	if (ptr) status = (*ptr).validateTasteQualities(1056);
	EXPECT_EQ(status, true);
}

TEST(TasteQualities_Tests, Apple_Level_1_QualitiesMask) {
	meal::TasteQualities qualities{ 1044 };
	EXPECT_EQ(qualities.getSalty(), 0);
	EXPECT_EQ(qualities.getAcidic(), 1);
	EXPECT_EQ(qualities.getSugary(), 1);
	EXPECT_EQ(qualities.getBitter(), 0);
	EXPECT_EQ(qualities.getFatty(), 0);
	EXPECT_EQ(qualities.getStiff(), 1);
	EXPECT_EQ(qualities.getHarsh(), 0);
	EXPECT_EQ(qualities.getHot(), 0);
}

TEST(TasteQualities_Tests, Apple_Qualities_Valid_Level_1_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14010101, 1, 100);
	if (ptr) status = (*ptr).validateTasteQualities(1044);
	EXPECT_EQ(status, true);
}

TEST(TasteQualities_Tests, Apple_Level_2_QualitiesMask) {
	meal::TasteQualities qualities{ 2056 };
	EXPECT_EQ(qualities.getSalty(), 0);
	EXPECT_EQ(qualities.getAcidic(), 2);
	EXPECT_EQ(qualities.getSugary(), 0);
	EXPECT_EQ(qualities.getBitter(), 0);
	EXPECT_EQ(qualities.getFatty(), 0);
	EXPECT_EQ(qualities.getStiff(), 2);
	EXPECT_EQ(qualities.getHarsh(), 0);
	EXPECT_EQ(qualities.getHot(), 0);
}

TEST(TasteQualities_Tests, Apple_Qualities_Valid_Level_2_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14010101, 2, 100);
	if (ptr) status = (*ptr).validateTasteQualities(2056);
	EXPECT_EQ(status, true);
}

TEST(TasteQualities_Tests, Apple_Level_3_QualitiesMask) {
	meal::TasteQualities qualities{ 3084 };
	EXPECT_EQ(qualities.getSalty(), 0);
	EXPECT_EQ(qualities.getAcidic(), 3);
	EXPECT_EQ(qualities.getSugary(), 0);
	EXPECT_EQ(qualities.getBitter(), 0);
	EXPECT_EQ(qualities.getFatty(), 0);
	EXPECT_EQ(qualities.getStiff(), 3);
	EXPECT_EQ(qualities.getHarsh(), 0);
	EXPECT_EQ(qualities.getHot(), 0);
}

TEST(TasteQualities_Tests, Apple_Qualities_Valid_Level_3_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14010101, 3, 100);
	if (ptr) status = (*ptr).validateTasteQualities(3084);
	EXPECT_EQ(status, true);
}


/*	Pear Tests */

TEST(TasteQualities_Tests, Pear_Level_0_QualitiesMask) {
	meal::TasteQualities qualities{ 1056 };
	EXPECT_EQ(qualities.getSalty(), 0);
	EXPECT_EQ(qualities.getAcidic(), 0);
	EXPECT_EQ(qualities.getSugary(), 2);
	EXPECT_EQ(qualities.getBitter(), 0);
	EXPECT_EQ(qualities.getFatty(), 0);
	EXPECT_EQ(qualities.getStiff(), 1);
	EXPECT_EQ(qualities.getHarsh(), 0);
	EXPECT_EQ(qualities.getHot(), 0);
}

TEST(TasteQualities_Tests, Pear_Qualities_Valid_Level_0_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14010102, 0, 100);
	if (ptr) status = (*ptr).validateTasteQualities(1056);
	EXPECT_EQ(status, true);
}

TEST(TasteQualities_Tests, Pear_Level_1_QualitiesMask) {
	meal::TasteQualities qualities{ 1104 };
	EXPECT_EQ(qualities.getSalty(), 0);
	EXPECT_EQ(qualities.getAcidic(), 0);
	EXPECT_EQ(qualities.getSugary(), 1);
	EXPECT_EQ(qualities.getBitter(), 1);
	EXPECT_EQ(qualities.getFatty(), 0);
	EXPECT_EQ(qualities.getStiff(), 1);
	EXPECT_EQ(qualities.getHarsh(), 0);
	EXPECT_EQ(qualities.getHot(), 0);
}

TEST(TasteQualities_Tests, Pear_Qualities_Valid_Level_1_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14010102, 1, 100);
	if (ptr) status = (*ptr).validateTasteQualities(1104);
	EXPECT_EQ(status, true);
}

TEST(TasteQualities_Tests, Pear_Level_2_QualitiesMask) {
	meal::TasteQualities qualities{ 2176 };
	EXPECT_EQ(qualities.getSalty(), 0);
	EXPECT_EQ(qualities.getAcidic(), 0);
	EXPECT_EQ(qualities.getSugary(), 0);
	EXPECT_EQ(qualities.getBitter(), 2);
	EXPECT_EQ(qualities.getFatty(), 0);
	EXPECT_EQ(qualities.getStiff(), 2);
	EXPECT_EQ(qualities.getHarsh(), 0);
	EXPECT_EQ(qualities.getHot(), 0);
}

TEST(TasteQualities_Tests, Pear_Qualities_Valid_Level_2_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14010102, 2, 100);
	if (ptr) status = (*ptr).validateTasteQualities(2176);
	EXPECT_EQ(status, true);
}

TEST(TasteQualities_Tests, Pear_Level_3_QualitiesMask) {
	meal::TasteQualities qualities{ 3264 };
	EXPECT_EQ(qualities.getSalty(), 0);
	EXPECT_EQ(qualities.getAcidic(), 0);
	EXPECT_EQ(qualities.getSugary(), 0);
	EXPECT_EQ(qualities.getBitter(), 3);
	EXPECT_EQ(qualities.getFatty(), 0);
	EXPECT_EQ(qualities.getStiff(), 3);
	EXPECT_EQ(qualities.getHarsh(), 0);
	EXPECT_EQ(qualities.getHot(), 0);
}

TEST(TasteQualities_Tests, Pear_Qualities_Valid_Level_3_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14010102, 3, 100);
	if (ptr) status = (*ptr).validateTasteQualities(3264);
	EXPECT_EQ(status, true);
}


/*	Plum Tests */

TEST(TasteQualities_Tests, Plum_Level_0_QualitiesMask) {
	meal::TasteQualities qualities{ 32 };
	EXPECT_EQ(qualities.getSalty(), 0);
	EXPECT_EQ(qualities.getAcidic(), 0);
	EXPECT_EQ(qualities.getSugary(), 2);
	EXPECT_EQ(qualities.getBitter(), 0);
	EXPECT_EQ(qualities.getFatty(), 0);
	EXPECT_EQ(qualities.getStiff(), 0);
	EXPECT_EQ(qualities.getHarsh(), 0);
	EXPECT_EQ(qualities.getHot(), 0);
}

TEST(TasteQualities_Tests, Plum_Qualities_Valid_Level_0_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14010103, 0, 100);
	if (ptr) status = (*ptr).validateTasteQualities(32);
	EXPECT_EQ(status, true);
}

TEST(TasteQualities_Tests, Plum_Level_1_QualitiesMask) {
	meal::TasteQualities qualities{ 5140 };
	EXPECT_EQ(qualities.getSalty(), 0);
	EXPECT_EQ(qualities.getAcidic(), 1);
	EXPECT_EQ(qualities.getSugary(), 1);
	EXPECT_EQ(qualities.getBitter(), 0);
	EXPECT_EQ(qualities.getFatty(), 0);
	EXPECT_EQ(qualities.getStiff(), 1);
	EXPECT_EQ(qualities.getHarsh(), 1);
	EXPECT_EQ(qualities.getHot(), 0);
}

TEST(TasteQualities_Tests, Plum_Qualities_Valid_Level_1_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14010103, 1, 100);
	if (ptr) status = (*ptr).validateTasteQualities(5140);
	EXPECT_EQ(status, true);
}

TEST(TasteQualities_Tests, Plum_Level_2_QualitiesMask) {
	meal::TasteQualities qualities{ 9224 };
	EXPECT_EQ(qualities.getSalty(), 0);
	EXPECT_EQ(qualities.getAcidic(), 2);
	EXPECT_EQ(qualities.getSugary(), 0);
	EXPECT_EQ(qualities.getBitter(), 0);
	EXPECT_EQ(qualities.getFatty(), 0);
	EXPECT_EQ(qualities.getStiff(), 1);
	EXPECT_EQ(qualities.getHarsh(), 2);
	EXPECT_EQ(qualities.getHot(), 0);
}

TEST(TasteQualities_Tests, Plum_Qualities_Valid_Level_2_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14010103, 2, 100);
	if (ptr) status = (*ptr).validateTasteQualities(9224);
	EXPECT_EQ(status, true);
}

TEST(TasteQualities_Tests, Plum_Level_3_QualitiesMask) {
	meal::TasteQualities qualities{ 14348 };
	EXPECT_EQ(qualities.getSalty(), 0);
	EXPECT_EQ(qualities.getAcidic(), 3);
	EXPECT_EQ(qualities.getSugary(), 0);
	EXPECT_EQ(qualities.getBitter(), 0);
	EXPECT_EQ(qualities.getFatty(), 0);
	EXPECT_EQ(qualities.getStiff(), 2);
	EXPECT_EQ(qualities.getHarsh(), 3);
	EXPECT_EQ(qualities.getHot(), 0);
}

TEST(TasteQualities_Tests, Plum_Qualities_Valid_Level_3_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14010103, 3, 100);
	if (ptr) status = (*ptr).validateTasteQualities(14348);
	EXPECT_EQ(status, true);
}


/*	Orange Tests */

TEST(TasteQualities_Tests, Orange_Level_0_QualitiesMask) {
	meal::TasteQualities qualities{ 32 };
	EXPECT_EQ(qualities.getSalty(), 0);
	EXPECT_EQ(qualities.getAcidic(), 0);
	EXPECT_EQ(qualities.getSugary(), 2);
	EXPECT_EQ(qualities.getBitter(), 0);
	EXPECT_EQ(qualities.getFatty(), 0);
	EXPECT_EQ(qualities.getStiff(), 0);
	EXPECT_EQ(qualities.getHarsh(), 0);
	EXPECT_EQ(qualities.getHot(), 0);
}

TEST(TasteQualities_Tests, Orange_Qualities_Valid_Level_0_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14020101, 0, 100);
	if (ptr) status = (*ptr).validateTasteQualities(32);
	EXPECT_EQ(status, true);
}

TEST(TasteQualities_Tests, Orange_Level_1_QualitiesMask) {
	meal::TasteQualities qualities{ 1044 };
	EXPECT_EQ(qualities.getSalty(), 0);
	EXPECT_EQ(qualities.getAcidic(), 1);
	EXPECT_EQ(qualities.getSugary(), 1);
	EXPECT_EQ(qualities.getBitter(), 0);
	EXPECT_EQ(qualities.getFatty(), 0);
	EXPECT_EQ(qualities.getStiff(), 1);
	EXPECT_EQ(qualities.getHarsh(), 0);
	EXPECT_EQ(qualities.getHot(), 0);
}

TEST(TasteQualities_Tests, Orange_Qualities_Valid_Level_1_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14020101, 1, 100);
	if (ptr) status = (*ptr).validateTasteQualities(1044);
	EXPECT_EQ(status, true);
}

TEST(TasteQualities_Tests, Orange_Level_2_QualitiesMask) {
	meal::TasteQualities qualities{ 2056 };
	EXPECT_EQ(qualities.getSalty(), 0);
	EXPECT_EQ(qualities.getAcidic(), 2);
	EXPECT_EQ(qualities.getSugary(), 0);
	EXPECT_EQ(qualities.getBitter(), 0);
	EXPECT_EQ(qualities.getFatty(), 0);
	EXPECT_EQ(qualities.getStiff(), 2);
	EXPECT_EQ(qualities.getHarsh(), 0);
	EXPECT_EQ(qualities.getHot(), 0);
}

TEST(TasteQualities_Tests, Orange_Qualities_Valid_Level_2_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14020101, 2, 100);
	if (ptr) status = (*ptr).validateTasteQualities(2056);
	EXPECT_EQ(status, true);
}

TEST(TasteQualities_Tests, Orange_Level_3_QualitiesMask) {
	meal::TasteQualities qualities{ 3084 };
	EXPECT_EQ(qualities.getSalty(), 0);
	EXPECT_EQ(qualities.getAcidic(), 3);
	EXPECT_EQ(qualities.getSugary(), 0);
	EXPECT_EQ(qualities.getBitter(), 0);
	EXPECT_EQ(qualities.getFatty(), 0);
	EXPECT_EQ(qualities.getStiff(), 3);
	EXPECT_EQ(qualities.getHarsh(), 0);
	EXPECT_EQ(qualities.getHot(), 0);
}

TEST(TasteQualities_Tests, Orange_Qualities_Valid_Level_3_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14020101, 3, 100);
	if (ptr) status = (*ptr).validateTasteQualities(3084);
	EXPECT_EQ(status, true);
}

/*	Granate Tests */

TEST(TasteQualities_Tests, Granate_Level_0_QualitiesMask) {
	meal::TasteQualities qualities{ 32 };
	EXPECT_EQ(qualities.getSalty(), 0);
	EXPECT_EQ(qualities.getAcidic(), 0);
	EXPECT_EQ(qualities.getSugary(), 2);
	EXPECT_EQ(qualities.getBitter(), 0);
	EXPECT_EQ(qualities.getFatty(), 0);
	EXPECT_EQ(qualities.getStiff(), 0);
	EXPECT_EQ(qualities.getHarsh(), 0);
	EXPECT_EQ(qualities.getHot(), 0);
}

TEST(TasteQualities_Tests, Granate_Qualities_Valid_Level_0_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14020102, 0, 100);
	if (ptr) status = (*ptr).validateTasteQualities(32);
	EXPECT_EQ(status, true);
}

TEST(TasteQualities_Tests, Granate_Level_1_QualitiesMask) {
	meal::TasteQualities qualities{ 5204 };
	EXPECT_EQ(qualities.getSalty(), 0);
	EXPECT_EQ(qualities.getAcidic(), 1);
	EXPECT_EQ(qualities.getSugary(), 1);
	EXPECT_EQ(qualities.getBitter(), 1);
	EXPECT_EQ(qualities.getFatty(), 0);
	EXPECT_EQ(qualities.getStiff(), 1);
	EXPECT_EQ(qualities.getHarsh(), 1);
	EXPECT_EQ(qualities.getHot(), 0);
}

TEST(TasteQualities_Tests, Granate_Qualities_Valid_Level_1_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14020102, 1, 100);
	if (ptr) status = (*ptr).validateTasteQualities(5204);
	EXPECT_EQ(status, true);
}

TEST(TasteQualities_Tests, Granate_Level_2_QualitiesMask) {
	meal::TasteQualities qualities{ 5256 };
	EXPECT_EQ(qualities.getSalty(), 0);
	EXPECT_EQ(qualities.getAcidic(), 2);
	EXPECT_EQ(qualities.getSugary(), 0);
	EXPECT_EQ(qualities.getBitter(), 2);
	EXPECT_EQ(qualities.getFatty(), 0);
	EXPECT_EQ(qualities.getStiff(), 1);
	EXPECT_EQ(qualities.getHarsh(), 1);
	EXPECT_EQ(qualities.getHot(), 0);
}

TEST(TasteQualities_Tests, Granate_Qualities_Valid_Level_2_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14020102, 2, 100);
	if (ptr) status = (*ptr).validateTasteQualities(5256);
	EXPECT_EQ(status, true);
}

TEST(TasteQualities_Tests, Granate_Level_3_QualitiesMask) {
	meal::TasteQualities qualities{ 10444 };
	EXPECT_EQ(qualities.getSalty(), 0);
	EXPECT_EQ(qualities.getAcidic(), 3);
	EXPECT_EQ(qualities.getSugary(), 0);
	EXPECT_EQ(qualities.getBitter(), 3);
	EXPECT_EQ(qualities.getFatty(), 0);
	EXPECT_EQ(qualities.getStiff(), 2);
	EXPECT_EQ(qualities.getHarsh(), 2);
	EXPECT_EQ(qualities.getHot(), 0);
}

TEST(TasteQualities_Tests, Granate_Qualities_Valid_Level_3_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14020102, 3, 100);
	if (ptr) status = (*ptr).validateTasteQualities(10444);
	EXPECT_EQ(status, true);
}


/*	Persimmon Tests */

TEST(TasteQualities_Tests, Persimmon_Level_0_QualitiesMask) {
	meal::TasteQualities qualities{ 32 };
	EXPECT_EQ(qualities.getSalty(), 0);
	EXPECT_EQ(qualities.getAcidic(), 0);
	EXPECT_EQ(qualities.getSugary(), 2);
	EXPECT_EQ(qualities.getBitter(), 0);
	EXPECT_EQ(qualities.getFatty(), 0);
	EXPECT_EQ(qualities.getStiff(), 0);
	EXPECT_EQ(qualities.getHarsh(), 0);
	EXPECT_EQ(qualities.getHot(), 0);
}

TEST(TasteQualities_Tests, Persimmon_Qualities_Valid_Level_0_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14020103, 0, 100);
	if (ptr) status = (*ptr).validateTasteQualities(32);
	EXPECT_EQ(status, true);
}

TEST(TasteQualities_Tests, Persimmon_Level_1_QualitiesMask) {
	meal::TasteQualities qualities{ 5200 };
	EXPECT_EQ(qualities.getSalty(), 0);
	EXPECT_EQ(qualities.getAcidic(), 0);
	EXPECT_EQ(qualities.getSugary(), 1);
	EXPECT_EQ(qualities.getBitter(), 1);
	EXPECT_EQ(qualities.getFatty(), 0);
	EXPECT_EQ(qualities.getStiff(), 1);
	EXPECT_EQ(qualities.getHarsh(), 1);
	EXPECT_EQ(qualities.getHot(), 0);
}

TEST(TasteQualities_Tests, Persimmon_Qualities_Valid_Level_1_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14020103, 1, 100);
	if (ptr) status = (*ptr).validateTasteQualities(5200);
	EXPECT_EQ(status, true);
}

TEST(TasteQualities_Tests, Persimmon_Level_2_QualitiesMask) {
	meal::TasteQualities qualities{ 10368 };
	EXPECT_EQ(qualities.getSalty(), 0);
	EXPECT_EQ(qualities.getAcidic(), 0);
	EXPECT_EQ(qualities.getSugary(), 0);
	EXPECT_EQ(qualities.getBitter(), 2);
	EXPECT_EQ(qualities.getFatty(), 0);
	EXPECT_EQ(qualities.getStiff(), 2);
	EXPECT_EQ(qualities.getHarsh(), 2);
	EXPECT_EQ(qualities.getHot(), 0);
}

TEST(TasteQualities_Tests, Persimmon_Qualities_Valid_Level_2_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14020103, 2, 100);
	if (ptr) status = (*ptr).validateTasteQualities(10368);
	EXPECT_EQ(status, true);
}

TEST(TasteQualities_Tests, Persimmon_Level_3_QualitiesMask) {
	meal::TasteQualities qualities{ 15552 };
	EXPECT_EQ(qualities.getSalty(), 0);
	EXPECT_EQ(qualities.getAcidic(), 0);
	EXPECT_EQ(qualities.getSugary(), 0);
	EXPECT_EQ(qualities.getBitter(), 3);
	EXPECT_EQ(qualities.getFatty(), 0);
	EXPECT_EQ(qualities.getStiff(), 3);
	EXPECT_EQ(qualities.getHarsh(), 3);
	EXPECT_EQ(qualities.getHot(), 0);
}

TEST(TasteQualities_Tests, Persimmon_Qualities_Valid_Level_3_Mask) {

	auto& mealFactory = meal::MealFactory::instance();
	if (mealFactory.noAvailableKeys()) {
		meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
		meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};
		mealFactory.supportedStandarts(tStandart, stStandart);
	}
	bool status = false;
	std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14020103, 3, 100);
	if (ptr) status = (*ptr).validateTasteQualities(15552);
	EXPECT_EQ(status, true);
}