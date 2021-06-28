#include "Meal.h"

namespace meal {

	std::shared_ptr<MealPropertiesModifier> EarlierMiddleAges_Temperate_MealStandart::applePropertiesModifier = nullptr;
	std::shared_ptr<MealPropertiesModifier> EarlierMiddleAges_Temperate_MealStandart::pearPropertiesModifier = nullptr;
	std::shared_ptr<MealPropertiesModifier> EarlierMiddleAges_Temperate_MealStandart::plumPropertiesModifier = nullptr;

	std::shared_ptr<MealPropertiesModifier> EarlierMiddleAges_Temperate_MealStandart::getApplePropertiesModifier() {
		if (not applePropertiesModifier) {

			Nutrients nutrients{ 40, 40, 980 };
			TasteQualities qualities{};
			Calories calories{ 4700 };
			Moisture moisture{ 80 };
			auto now = std::chrono::system_clock::now();
			uint8_t expritationConst = 35;
			auto expritationChrono = now + std::chrono::hours(numHours * expritationConst);
			MealDate date{ now, expritationChrono };
			StorageTemperature temperature{ 24, 16, 10 };
			MealVitamins vitamins{ 72075323932480274 };
			MealMinerals minerals{ 1229767540789547265 };

			MealProperties properties(nutrients, qualities, calories, moisture, date, temperature);
			properties.initNutrients( std::move(nutrients) );
			properties.initTasteQualities( std::move(qualities) );
			properties.initCalories(calories);
			properties.initMoisture(moisture);
			properties.initDate(std::move(date));
			properties.initTemperature(std::move(temperature));
			properties.initVitamins(std::move(vitamins));
			properties.initMinerals(std::move(minerals));

			MealPropertiesModifier modifier{ properties };
			modifier.addMode(std::make_shared<TasteQualities_MealMode>(TasteQualities_MealMode{ 1056 }), 0);
			modifier.addMode(LevelDowngrade_MealMode::level_1_mode, 1);
			modifier.addMode(std::make_shared<TasteQualities_MealMode>(TasteQualities_MealMode{ 1044 }), 1);
			modifier.addMode(LevelDowngrade_MealMode::level_2_mode, 2);
			modifier.addMode(std::make_shared<TasteQualities_MealMode>(TasteQualities_MealMode{ 2056 }), 2);
			modifier.addMode(LevelDowngrade_MealMode::level_3_mode, 3);
			modifier.addMode(std::make_shared<TasteQualities_MealMode>(TasteQualities_MealMode{ 3084 }), 3);
			applePropertiesModifier = std::make_shared<MealPropertiesModifier>(modifier);

		}
		return applePropertiesModifier;
	}

	std::shared_ptr<MealPropertiesModifier> EarlierMiddleAges_Temperate_MealStandart::getPearPropertiesModifier() {
		if (not pearPropertiesModifier) {

			Nutrients nutrients{ 40, 30, 1100 };
			TasteQualities qualities{};
			Calories calories{ 4200 };
			Moisture moisture{ 86 };
			auto now = std::chrono::system_clock::now();
			uint8_t expritationConst = 25;
			auto expritationChrono = now + std::chrono::hours(numHours * expritationConst);
			MealDate date{ now, expritationChrono };
			StorageTemperature temperature{ 24, 16, 10 };
			MealVitamins vitamins{ 72374391632101649 };
			MealMinerals minerals{ 1152941369116922113 };

			MealProperties properties(nutrients, qualities, calories, moisture, date, temperature);
			properties.initNutrients(std::move(nutrients));
			properties.initTasteQualities(std::move(qualities));
			properties.initCalories(calories);
			properties.initMoisture(moisture);
			properties.initDate(std::move(date));
			properties.initTemperature(std::move(temperature));
			properties.initVitamins(std::move(vitamins));
			properties.initMinerals(std::move(minerals));

			MealPropertiesModifier modifier{ properties };
			modifier.addMode(std::make_shared<TasteQualities_MealMode>(TasteQualities_MealMode{ 1056 }), 0);
			modifier.addMode(LevelDowngrade_MealMode::level_1_mode, 1);
			modifier.addMode(std::make_shared<TasteQualities_MealMode>(TasteQualities_MealMode{ 1104 }), 1);
			modifier.addMode(LevelDowngrade_MealMode::level_2_mode, 2);
			modifier.addMode(std::make_shared<TasteQualities_MealMode>(TasteQualities_MealMode{ 2176 }), 2);
			modifier.addMode(LevelDowngrade_MealMode::level_3_mode, 3);
			modifier.addMode(std::make_shared<TasteQualities_MealMode>(TasteQualities_MealMode{ 3264 }), 3);
			pearPropertiesModifier = std::make_shared<MealPropertiesModifier>(modifier);
		}
		return pearPropertiesModifier;
	}

	std::shared_ptr<MealPropertiesModifier> EarlierMiddleAges_Temperate_MealStandart::getPlumPropertiesModifier() {
		if (not plumPropertiesModifier) {

			Nutrients nutrients{ 80, 30, 960 };
			TasteQualities qualities{};
			Calories calories{ 4200 };
			Moisture moisture{ 70 };
			auto now = std::chrono::system_clock::now();
			uint8_t expritationConst = 30;
			auto expritationChrono = now + std::chrono::hours(numHours * expritationConst);
			MealDate date{ now, expritationChrono };
			StorageTemperature temperature{ 24, 16, 10 };
			MealVitamins vitamins{ 72110508304568593 };
			MealMinerals minerals{ 1229766514577576210 };

			MealProperties properties(nutrients, qualities, calories, moisture, date, temperature);
			properties.initNutrients(std::move(nutrients));
			properties.initTasteQualities(std::move(qualities));
			properties.initCalories(calories);
			properties.initMoisture(moisture);
			properties.initDate(std::move(date));
			properties.initTemperature(std::move(temperature));
			properties.initVitamins(std::move(vitamins));
			properties.initMinerals(std::move(minerals));

			MealPropertiesModifier modifier{ properties };
			modifier.addMode(std::make_shared<TasteQualities_MealMode>(TasteQualities_MealMode{ 32 }), 0);
			modifier.addMode(LevelDowngrade_MealMode::level_1_mode, 1);
			modifier.addMode(std::make_shared<TasteQualities_MealMode>(TasteQualities_MealMode{ 5140 }), 1);
			modifier.addMode(LevelDowngrade_MealMode::level_2_mode, 2);
			modifier.addMode(std::make_shared<TasteQualities_MealMode>(TasteQualities_MealMode{ 9224 }), 2);
			modifier.addMode(LevelDowngrade_MealMode::level_3_mode, 3);
			modifier.addMode(std::make_shared<TasteQualities_MealMode>(TasteQualities_MealMode{ 14348 }), 3);
			plumPropertiesModifier = std::make_shared<MealPropertiesModifier>(modifier);
		}
		return plumPropertiesModifier;
	}

	std::shared_ptr<MealPropertiesModifier> EarlierMiddleAges_SubTropic_MealStandart::orangePropertiesModifier = nullptr;
	std::shared_ptr<MealPropertiesModifier> EarlierMiddleAges_SubTropic_MealStandart::granatePropertiesModifier = nullptr;
	std::shared_ptr<MealPropertiesModifier> EarlierMiddleAges_SubTropic_MealStandart::persimmonPropertiesModifier = nullptr;

	std::shared_ptr<MealPropertiesModifier> EarlierMiddleAges_SubTropic_MealStandart::getOrangePropertiesModifier() {
		if (not orangePropertiesModifier) {

			Nutrients nutrients{ 90, 20, 810 };
			TasteQualities qualities{};
			Calories calories{ 3600 };
			Moisture moisture{ 90 };
			auto now = std::chrono::system_clock::now();
			uint8_t expritationConst = 30;
			auto expritationChrono = now + std::chrono::hours(numHours * expritationConst);
			MealDate date{ now, expritationChrono };
			StorageTemperature temperature{ 24, 16, 10 };
			MealVitamins vitamins{ 72075323931365649 };
			MealMinerals minerals{ 1152921573596860674 };

			MealProperties properties(nutrients, qualities, calories, moisture, date, temperature);
			properties.initNutrients(std::move(nutrients));
			properties.initTasteQualities(std::move(qualities));
			properties.initCalories(calories);
			properties.initMoisture(moisture);
			properties.initDate(std::move(date));
			properties.initTemperature(std::move(temperature));
			properties.initVitamins(std::move(vitamins));
			properties.initMinerals(std::move(minerals));

			MealPropertiesModifier modifier{ properties };
			modifier.addMode(std::make_shared<TasteQualities_MealMode>(TasteQualities_MealMode{ 32 }), 0);
			modifier.addMode(LevelDowngrade_MealMode::level_1_mode, 1);
			modifier.addMode(std::make_shared<TasteQualities_MealMode>(TasteQualities_MealMode{ 1044 }), 1);
			modifier.addMode(LevelDowngrade_MealMode::level_2_mode, 2);
			modifier.addMode(std::make_shared<TasteQualities_MealMode>(TasteQualities_MealMode{ 2056 }), 2);
			modifier.addMode(LevelDowngrade_MealMode::level_3_mode, 3);
			modifier.addMode(std::make_shared<TasteQualities_MealMode>(TasteQualities_MealMode{ 3084 }), 3);
			orangePropertiesModifier = std::make_shared<MealPropertiesModifier>(modifier);
		}
		return orangePropertiesModifier;
	}

	std::shared_ptr<MealPropertiesModifier> EarlierMiddleAges_SubTropic_MealStandart::getGranatePropertiesModifier() {
		if (not granatePropertiesModifier) {

			Nutrients nutrients{ 90, 0, 1400 };
			TasteQualities qualities{};
			Calories calories{ 5200 };
			Moisture moisture{ 80 };
			auto now = std::chrono::system_clock::now();
			uint8_t expritationConst = 60;
			auto expritationChrono = now + std::chrono::hours(numHours * expritationConst);
			MealDate date{ now, expritationChrono };
			StorageTemperature temperature{ 24, 16, 10 };
			MealVitamins vitamins{ 72638278180868369 };
			MealMinerals minerals{ 1152921573596860674 };

			MealProperties properties(nutrients, qualities, calories, moisture, date, temperature);
			properties.initNutrients(std::move(nutrients));
			properties.initTasteQualities(std::move(qualities));
			properties.initCalories(calories);
			properties.initMoisture(moisture);
			properties.initDate(std::move(date));
			properties.initTemperature(std::move(temperature));
			properties.initVitamins(std::move(vitamins));
			properties.initMinerals(std::move(minerals));

			MealPropertiesModifier modifier{ properties };
			modifier.addMode(std::make_shared<TasteQualities_MealMode>(TasteQualities_MealMode{ 32 }), 0);
			modifier.addMode(LevelDowngrade_MealMode::level_1_mode, 1);
			modifier.addMode(std::make_shared<TasteQualities_MealMode>(TasteQualities_MealMode{ 5204 }), 1);
			modifier.addMode(LevelDowngrade_MealMode::level_2_mode, 2);
			modifier.addMode(std::make_shared<TasteQualities_MealMode>(TasteQualities_MealMode{ 5256 }), 2);
			modifier.addMode(LevelDowngrade_MealMode::level_3_mode, 3);
			modifier.addMode(std::make_shared<TasteQualities_MealMode>(TasteQualities_MealMode{ 10444 }), 3);
			granatePropertiesModifier = std::make_shared<MealPropertiesModifier>(modifier);
		}
		return granatePropertiesModifier;
	}

	std::shared_ptr<MealPropertiesModifier> EarlierMiddleAges_SubTropic_MealStandart::getPersimmonPropertiesModifier() {
		if (not persimmonPropertiesModifier) {

			Nutrients nutrients{ 50, 40, 1550 };
			TasteQualities qualities{};
			Calories calories{ 6700 };
			Moisture moisture{ 70 };
			auto now = std::chrono::system_clock::now();
			uint8_t expritationConst = 50;
			auto expritationChrono = now + std::chrono::hours(numHours * expritationConst);
			MealDate date{ now, expritationChrono };
			StorageTemperature temperature{ 24, 16, 10 };
			MealVitamins vitamins{ 72356730189844752 };
			MealMinerals minerals{ 1225280438131560705 };

			MealProperties properties(nutrients, qualities, calories, moisture, date, temperature);
			properties.initNutrients(std::move(nutrients));
			properties.initTasteQualities(std::move(qualities));
			properties.initCalories(calories);
			properties.initMoisture(moisture);
			properties.initDate(std::move(date));
			properties.initTemperature(std::move(temperature));
			properties.initVitamins(std::move(vitamins));
			properties.initMinerals(std::move(minerals));

			MealPropertiesModifier modifier{ properties };
			modifier.addMode(std::make_shared<TasteQualities_MealMode>(TasteQualities_MealMode{ 32 }), 0);
			modifier.addMode(LevelDowngrade_MealMode::level_1_mode, 1);
			modifier.addMode(std::make_shared<TasteQualities_MealMode>(TasteQualities_MealMode{ 5200 }), 1);
			modifier.addMode(LevelDowngrade_MealMode::level_2_mode, 2);
			modifier.addMode(std::make_shared<TasteQualities_MealMode>(TasteQualities_MealMode{ 10368 }), 2);
			modifier.addMode(LevelDowngrade_MealMode::level_3_mode, 3);
			modifier.addMode(std::make_shared<TasteQualities_MealMode>(TasteQualities_MealMode{ 15552 }), 3);
			persimmonPropertiesModifier = std::make_shared<MealPropertiesModifier>(modifier);
		}
		return persimmonPropertiesModifier;
	}
}