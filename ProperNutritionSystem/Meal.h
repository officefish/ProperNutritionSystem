#include <stdint.h>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <optional>
#include <functional>
#include <sstream>
#include <bitset>
#include <memory>

namespace utilities {
	inline std::tm localtime_xp(std::time_t timer)
	{
		std::tm bt{};
#if defined(__unix__)
		localtime_r(&timer, &bt);
#elif defined(_MSC_VER)
		localtime_s(&bt, &timer);
#else
		static std::mutex mtx;
		std::lock_guard<std::mutex> lock(mtx);
		bt = *std::localtime(&timer);
#endif
		return bt;
	}

	// default = "YYYY-MM-DD HH:MM:SS"
	inline std::string time_stamp(time_t time, const std::string& fmt = "%F %T")
	{
		auto bt = localtime_xp(time);
		char buf[64];
		return { buf, std::strftime(buf, sizeof(buf), fmt.c_str(), &bt) };
	}
}

namespace meal {

	class Nutrients final {
		int16_t _nProteins;
		int16_t _nFats;
		int16_t _nCarbohydrates;

	public:
		Nutrients() = delete;
		~Nutrients() = default;

		explicit Nutrients(int16_t proteins, int16_t fats, int16_t carbohydrates)
			noexcept :
			_nProteins(proteins),
			_nFats(fats),
			_nCarbohydrates(carbohydrates)
		{};

		Nutrients(const Nutrients& nutrients) noexcept;
		Nutrients& operator= (const Nutrients& nutrients) noexcept;

		Nutrients(Nutrients&& nutrients) noexcept;
		Nutrients& operator= (Nutrients&& nutrients) noexcept;

		Nutrients(const std::initializer_list<int16_t>& nutrients) noexcept;

		std::string toString() const;
		void toStream(std::ostream& cout) noexcept;

		void upgrade(uint16_t percents) noexcept;

		int16_t proteins() const { return _nProteins; };
		int16_t fats() const { return _nFats; };
		int16_t carbohydrates() const { return _nCarbohydrates; };
	};

	class MealVitamins final {
	private:
		uint64_t _bVitamins;
		uint64_t validValue(uint64_t value) noexcept;

	public:
		static constexpr uint64_t MAX_VALUE{ 0xF };

		static constexpr uint64_t A				{ 0x000000000000000F };
		static constexpr uint64_t B1			{ 0x00000000000000F0 };
		static constexpr uint64_t B2			{ 0x0000000000000F00 };
		static constexpr uint64_t B3			{ 0x000000000000F000 };

		static constexpr uint64_t B5			{ 0x00000000000F0000 };
		static constexpr uint64_t B6			{ 0x0000000000F00000 };
		static constexpr uint64_t B7			{ 0x000000000F000000 };
		static constexpr uint64_t B9			{ 0x00000000F0000000 };

		static constexpr uint64_t B12			{ 0x0000000F00000000 };
		static constexpr uint64_t C				{ 0x000000F000000000 };
		static constexpr uint64_t D				{ 0x00000F0000000000 };
		static constexpr uint64_t E				{ 0x0000F00000000000 };

		static constexpr uint64_t K				{ 0x000F000000000000 };
		static constexpr uint64_t N				{ 0x00F0000000000000 };
		static constexpr uint64_t P				{ 0x0F00000000000000 };
		static constexpr uint64_t U				{ 0xF000000000000000 };

		MealVitamins() : _bVitamins(0) {};
		~MealVitamins() = default;
		explicit MealVitamins(uint64_t vitamins)
			noexcept :
			_bVitamins(vitamins)
		{};

		explicit MealVitamins(const std::string& vitamins) noexcept;

		MealVitamins(const MealVitamins& vitamins) noexcept;
		MealVitamins& operator= (const MealVitamins& ) noexcept;

		MealVitamins(MealVitamins&& vitamins) noexcept;
		MealVitamins& operator= (MealVitamins&& vitamins) noexcept;

		void setA(uint64_t value) noexcept;
		void setB1(uint64_t value) noexcept;
		void setB2(uint64_t value) noexcept;
		void setB3(uint64_t value) noexcept;

		void setB5(uint64_t value) noexcept;
		void setB6(uint64_t value) noexcept;
		void setB7(uint64_t value) noexcept;
		void setB9(uint64_t value) noexcept;

		void setB12(uint64_t value) noexcept;
		void setC(uint64_t value) noexcept;
		void setD(uint64_t value) noexcept;
		void setE(uint64_t value) noexcept;

		void setK(uint64_t value) noexcept;
		void setN(uint64_t value) noexcept;
		void setP(uint64_t value) noexcept;
		void setU(uint64_t value) noexcept;

		uint64_t getA() const noexcept;
		uint64_t getB1() const noexcept;
		uint64_t getB2() const noexcept;
		uint64_t getB3() const noexcept;

		uint64_t getB5() const noexcept;
		uint64_t getB6() const noexcept;
		uint64_t getB7() const noexcept;
		uint64_t getB9() const noexcept;

		uint64_t getB12() const noexcept;
		uint64_t getC() const noexcept;
		uint64_t getD() const noexcept;
		uint64_t getE() const noexcept;

		uint64_t getK() const noexcept;
		uint64_t getN() const noexcept;
		uint64_t getP() const noexcept;
		uint64_t getU() const noexcept;

		void toStream(std::ostream& cout) noexcept;
		void toBitsetStream(std::ostream& cout) noexcept;
		void toUlonglongStream(std::ostream& cout) noexcept;

		void upgrade(uint16_t percents) noexcept;

		friend bool operator== (const MealVitamins& v1, const MealVitamins& v2);
		friend bool operator!= (const MealVitamins& v1, const MealVitamins& v2);
	};

	class MealMinerals final {
	private:
		uint64_t _bMinerals;
		uint64_t validValue(uint64_t value) noexcept;

	public:
		static constexpr uint64_t MAX_VALUE { 0xF };

		static constexpr uint64_t K			{ 0x000000000000000F };	// калий
		static constexpr uint64_t Cl		{ 0x00000000000000F0 };	// хлориды
		static constexpr uint64_t Na		{ 0x0000000000000F00 };	// натрий
		static constexpr uint64_t Ca		{ 0x000000000000F000 };	// кальций

		static constexpr uint64_t P			{ 0x00000000000F0000 };	// фосфор
		static constexpr uint64_t Mg		{ 0x0000000000F00000 };	// магний
		static constexpr uint64_t Zn		{ 0x000000000F000000 };	// цинк
		static constexpr uint64_t Fe		{ 0x00000000F0000000 };	// железо

		static constexpr uint64_t Mn		{ 0x0000000F00000000 };	// марганец
		static constexpr uint64_t Cu		{ 0x000000F000000000 };	// медь
		static constexpr uint64_t I			{ 0x00000F0000000000 };	// йод
		static constexpr uint64_t Se		{ 0x0000F00000000000 };	// селен

		static constexpr uint64_t Mo		{ 0x000F000000000000 };	// молибден
		static constexpr uint64_t S			{ 0x00F0000000000000 }; // сера
		static constexpr uint64_t Cr		{ 0x0F00000000000000 };	// хром
		static constexpr uint64_t F			{ 0xF000000000000000 }; // фтор

		MealMinerals() : _bMinerals(0) {};
		~MealMinerals() = default;
		explicit MealMinerals(uint64_t minerals)
			noexcept :
			_bMinerals(minerals)
		{};

		explicit MealMinerals(const std::string & minerals) noexcept;

		MealMinerals(const MealMinerals & minerals) noexcept;
		MealMinerals& operator= (const MealMinerals&) noexcept;

		MealMinerals(MealMinerals && minerals) noexcept;
		MealMinerals& operator= (MealMinerals && minerals) noexcept;

		void setK(uint64_t value) noexcept;
		void setCl(uint64_t value) noexcept;
		void setNa(uint64_t value) noexcept;
		void setCa(uint64_t value) noexcept;

		void setP(uint64_t value) noexcept;
		void setMg(uint64_t value) noexcept;
		void setZn(uint64_t value) noexcept;
		void setFe(uint64_t value) noexcept;

		void setMn(uint64_t value) noexcept;
		void setCu(uint64_t value) noexcept;
		void setI(uint64_t value) noexcept;
		void setSe(uint64_t value) noexcept;

		void setMo(uint64_t value) noexcept;
		void setS(uint64_t value) noexcept;
		void setCr(uint64_t value) noexcept;
		void setF(uint64_t value) noexcept;

		uint64_t getK() const noexcept;
		uint64_t getCl() const noexcept;
		uint64_t getNa() const noexcept;
		uint64_t getCa() const noexcept;

		uint64_t getP() const noexcept;
		uint64_t getMg() const noexcept;
		uint64_t getZn() const noexcept;
		uint64_t getFe() const noexcept;

		uint64_t getMn() const noexcept;
		uint64_t getCu() const noexcept;
		uint64_t getI() const noexcept;
		uint64_t getSe() const noexcept;

		uint64_t getMo() const noexcept;
		uint64_t getS() const noexcept;
		uint64_t getCr() const noexcept;
		uint64_t getF() const noexcept;

		void toStream(std::ostream& cout) noexcept;
		void toBitsetStream(std::ostream& cout) noexcept;
		void toUlonglongStream(std::ostream& cout) noexcept;

		void upgrade(uint16_t percents) noexcept;

		friend bool operator== (const MealMinerals& m1, const MealMinerals& m2);
		friend bool operator!= (const MealMinerals& m1, const MealMinerals& m2);
	};

	class TasteQualities final {
	private:
		uint16_t _bQualities;
	private:
		std::string getStatus(uint16_t quality, uint16_t status);
		uint16_t validValue(uint16_t value) noexcept;

	public:
		static constexpr uint64_t MAX_VALUE		{ 0x3 };

		static constexpr uint16_t None			{ 0 };		// не ...
		static constexpr uint16_t Abstinently	{ 0x1 };	// умеренно ...
		static constexpr uint16_t Saturated		{ 0x2 };	// насыщенно ...
		static constexpr uint16_t Redundantly	{ 0x3 };	// избыточно ...

		static constexpr uint16_t Salty			{ 0x0003 };	// соленый
		static constexpr uint16_t Acidic		{ 0x000C }; // кислый
		static constexpr uint16_t Sugary		{ 0x0030 }; // сладкий
		static constexpr uint16_t Bitter		{ 0x00C0 }; // горький
		static constexpr uint16_t Fatty			{ 0x0300 }; // жирный
		static constexpr uint16_t Stiff			{ 0x0C00 }; // жесткий
		static constexpr uint16_t Harsh			{ 0x3000 }; // терпкий
		static constexpr uint16_t Hot			{ 0xC000 }; // жгучий

		TasteQualities() : _bQualities(0) {};
		~TasteQualities() = default;
		explicit TasteQualities(uint16_t qualities)
			noexcept :
			_bQualities(qualities)
		{};

		explicit TasteQualities(const std::string& qualities) noexcept;

		TasteQualities(const TasteQualities& qualities) noexcept;
		TasteQualities& operator= (const TasteQualities& qualities) noexcept;

		TasteQualities(TasteQualities&& qualities) noexcept;
		TasteQualities& operator= (TasteQualities&& qualities) noexcept;

		void update(uint16_t value) noexcept;

		void setSalty(uint16_t value);
		void setAcidic(uint16_t value);
		void setSugary(uint16_t value);
		void setBitter(uint16_t value);
		void setFatty(uint16_t value);
		void setStiff(uint16_t value);
		void setHarsh(uint16_t value);
		void setHot(uint16_t value);

		uint16_t getSalty();
		uint16_t getAcidic();
		uint16_t getSugary();
		uint16_t getBitter();
		uint16_t getFatty();
		uint16_t getStiff();
		uint16_t getHarsh();
		uint16_t getHot();

		void toStream(std::ostream& cout) noexcept;
		void toBitsetStream(std::ostream& cout) noexcept;
		void toUlongStream(std::ostream& cout) noexcept;

		friend bool operator== (const TasteQualities& q1, const TasteQualities& q2);
		friend bool operator!= (const TasteQualities& q1, const TasteQualities& q2);

	};

	class MealDate final {
		using time_point = std::chrono::time_point<std::chrono::system_clock>;

		time_t _tInitialDate;
		time_t _tExpritationDate;
	public:
		MealDate() = delete;
		~MealDate() = default;

		explicit MealDate(time_t initialDate, time_t expritationDate)
			noexcept :
			_tInitialDate(initialDate),
			_tExpritationDate(expritationDate)
		{};

		explicit MealDate(time_point&& initialPoint, time_point&& expritationPoint)
			noexcept :
			_tInitialDate(std::chrono::system_clock::to_time_t(initialPoint)),
			_tExpritationDate(std::chrono::system_clock::to_time_t(expritationPoint))
		{};

		MealDate(const MealDate& date) noexcept;
		MealDate& operator= (const MealDate& date) noexcept;

		MealDate(MealDate&& date) noexcept;
		MealDate& operator= (MealDate&& date) noexcept;

		MealDate(const std::initializer_list<time_t>& date) noexcept;
		MealDate(const std::initializer_list<time_point>& date) noexcept;

		void update(time_t newDate);

		std::string toString() const;
		void toStream(std::ostream& cout) noexcept;
	};

	class StorageTemperature final {
		int8_t _n8Current;
		int8_t _n8Reccomended;
		int8_t	_n8PermissibleDifference;

	public:
		StorageTemperature() = delete;
		~StorageTemperature() = default;

		explicit StorageTemperature(int8_t current, int8_t recommended, int8_t permDifference)
			noexcept :
			_n8Current(current),
			_n8Reccomended(recommended),
			_n8PermissibleDifference(permDifference)
		{};

		StorageTemperature(const std::initializer_list<int8_t>&) noexcept;

		StorageTemperature(const StorageTemperature& temperature) noexcept;
		StorageTemperature& operator= (const StorageTemperature& temperature) noexcept;

		StorageTemperature(StorageTemperature&& temperature) noexcept;
		StorageTemperature& operator= (StorageTemperature&& temperature) noexcept;

		std::string toString() const;
		void toStream(std::ostream& cout) noexcept;
	};

	class MealProperties {
		typedef uint16_t Calories;
		typedef uint16_t Moisture;

	private:
		std::optional<Nutrients> _oNutrients;
		std::optional<MealDate> _oMealDate;
		std::optional<StorageTemperature> _oTemperature;
		std::optional<TasteQualities> _oQualities;
		std::optional<MealVitamins> _oVitamins;
		std::optional<MealMinerals> _oMinerals;
		Calories _nCalories;
		Moisture _nMoisture;

	public:
		MealProperties();
		~MealProperties() = default; // ?
		MealProperties(Nutrients&&, TasteQualities&&, Calories, Moisture, MealDate&&, StorageTemperature&&) noexcept;
		MealProperties(const Nutrients&, const TasteQualities&, Calories, Moisture, const MealDate&, const StorageTemperature&) noexcept;

		MealProperties(const MealProperties& properties) noexcept;
		MealProperties& operator= (const MealProperties& properties) noexcept;

		MealProperties(MealProperties&& properties) noexcept;
		MealProperties& operator= (MealProperties&& properties) noexcept;

		void initNutrients(Nutrients&& nutrients) noexcept;
		void initTasteQualities(TasteQualities&& qualities) noexcept;
		void initCalories(Calories calories) noexcept;
		void initMoisture(Moisture moisture) noexcept;
		void initDate(MealDate&& date) noexcept;
		void initTemperature(StorageTemperature&& temperature) noexcept;
		void initVitamins(MealVitamins&& vitamins) noexcept;
		void initMinerals(MealMinerals&& minerals) noexcept;

		void setTasteQualities(uint16_t value);
		bool validateTasteQualities(uint16_t value);
		bool validateVitamins(uint64_t value);
		bool validateMinerals(uint64_t value);

		void upgradeCalories(uint16_t percents) noexcept;
		void upgradeMoisture(uint16_t percents) noexcept;
		void upgradeNutrients(uint16_t percents) noexcept;
		void upgradeVitamins(uint16_t percents) noexcept;
		void upgradeMinerals(uint16_t percents) noexcept;

		void updateDate(time_t date);

		void toStream(std::ostream& cout) noexcept;
	};

	class MealMode {
	protected:
		uint16_t _nValue;
	public:
		MealMode(uint16_t value) noexcept : _nValue(value) {};
		virtual ~MealMode() = default;
		void virtual modify(std::shared_ptr<MealProperties> propertiesPtr) { std::cout << "base modify" << std::endl; };

	};

	class TasteQualities_MealMode : public MealMode {
	public:
		explicit TasteQualities_MealMode(uint16_t value) noexcept : MealMode(value) {};
		~TasteQualities_MealMode() = default;

		using MealMode::modify;
		void modify(std::shared_ptr<MealProperties> propertiesPtr);
	};

	class LevelDowngrade_MealMode : public MealMode {
	public:
		static std::shared_ptr<MealMode> level_1_mode;
		static std::shared_ptr<MealMode> level_2_mode;
		static std::shared_ptr<MealMode> level_3_mode;
	public:
		explicit LevelDowngrade_MealMode(uint16_t value) noexcept : MealMode(value) {};
		~LevelDowngrade_MealMode() = default;

		using MealMode::modify;
		void modify(std::shared_ptr<MealProperties> propertiesPtr);
	};

	class MealWeight_MealMode : public MealMode {
	public:
		explicit MealWeight_MealMode(uint16_t value) noexcept : MealMode(value) {};
		~MealWeight_MealMode() = default;

		using MealMode::modify;
		void modify(std::shared_ptr<MealProperties> propertiesPtr);
	};

	class MealDate_MealMode : public MealMode {
		using time_point = std::chrono::time_point<std::chrono::system_clock>;
		time_t _tCurrentDate;
	public:
		explicit MealDate_MealMode(time_t currentDate) noexcept : MealMode(0) { _tCurrentDate = currentDate; };
		explicit MealDate_MealMode(time_point currentDate) noexcept; //{ _tCurrentDate = currentDate; };
		~MealDate_MealMode() = default;

		using MealMode::modify;
		void modify(std::shared_ptr<MealProperties> propertiesPtr);
	};

	class MealPropertiesModifier final {
	private:
		std::vector<std::shared_ptr<MealMode>> level_0_modes;
		std::vector<std::shared_ptr<MealMode>> level_1_modes;
		std::vector<std::shared_ptr<MealMode>> level_2_modes;
		std::vector<std::shared_ptr<MealMode>> level_3_modes;
		std::vector<std::shared_ptr<MealMode>>& getLevelModes(uint8_t level);
		std::optional<MealProperties> _oPropertiesPrototype;
		void modify(uint8_t level, std::shared_ptr<MealProperties> propertiesPtr);
	public:
		MealPropertiesModifier(MealProperties&& prototype);
		MealPropertiesModifier(const MealProperties& prototype);
		~MealPropertiesModifier() = default;

		void addMode(std::shared_ptr<MealMode> modePtr, uint8_t level);
		std::shared_ptr<MealProperties> getModifiedMealProperties(uint8_t level);

	};

	class MealStandart {
		typedef uint32_t Naming;
		using MealPropertiesModifierPtr = std::shared_ptr<MealPropertiesModifier>;
		using StandartMap = std::unordered_map<Naming, std::function<MealPropertiesModifierPtr()>>;

	protected:
		static constexpr uint8_t numHours = 24;
		StandartMap _mStandartMap;

	public:
		MealStandart() = default;
		virtual ~MealStandart() = default;

		void registerProducer(Naming naming, std::function<MealPropertiesModifierPtr()> producer) {
			_mStandartMap.insert({ naming, producer });
		}
		void merge(const MealStandart&) noexcept;
		MealPropertiesModifierPtr getModifier(Naming naming) noexcept;
		void availableKeys_toStream(std::ostream& cout) noexcept;
		bool noAvailableKeys() { return _mStandartMap.empty(); };
	};

	class EarlierMiddleAges_Temperate_MealStandart : public MealStandart {
		using MealPropertiesModifierPtr = std::shared_ptr<MealPropertiesModifier>;
		typedef int16_t Calories;
		typedef int16_t Moisture;
	private :
		static MealPropertiesModifierPtr applePropertiesModifier;
		static MealPropertiesModifierPtr pearPropertiesModifier;
		static MealPropertiesModifierPtr plumPropertiesModifier;
	private:
		static MealPropertiesModifierPtr getApplePropertiesModifier();
		static MealPropertiesModifierPtr getPearPropertiesModifier();
		static MealPropertiesModifierPtr getPlumPropertiesModifier();

	public:
		EarlierMiddleAges_Temperate_MealStandart() {
			this->registerProducer(14010101, getApplePropertiesModifier);
			this->registerProducer(14010102, getPearPropertiesModifier);
			this->registerProducer(14010103, getPlumPropertiesModifier);
		}
	};

	class EarlierMiddleAges_SubTropic_MealStandart : public MealStandart {
		using MealPropertiesModifierPtr = std::shared_ptr<MealPropertiesModifier>;
		typedef int16_t Calories;
		typedef int16_t Moisture;
	private:
		static MealPropertiesModifierPtr orangePropertiesModifier;
		static MealPropertiesModifierPtr granatePropertiesModifier;
		static MealPropertiesModifierPtr persimmonPropertiesModifier;
	private:
		static MealPropertiesModifierPtr getOrangePropertiesModifier();
		static MealPropertiesModifierPtr getGranatePropertiesModifier();
		static MealPropertiesModifierPtr getPersimmonPropertiesModifier();

	public:
		EarlierMiddleAges_SubTropic_MealStandart() {
			this->registerProducer(14020101, getOrangePropertiesModifier);
			this->registerProducer(14020102, getGranatePropertiesModifier);
			this->registerProducer(14020103, getPersimmonPropertiesModifier);
		}
	};

	class Meal {
		std::shared_ptr<MealProperties> _pProperties;
	public:
		Meal(std::shared_ptr<MealProperties> properties) noexcept : _pProperties(properties) {};
		bool validateTasteQualities(uint16_t value);
		bool validateVitamins(uint64_t value);
		bool validateMinerals(uint64_t value);
		void toStream(std::ostream& cout) noexcept;
	};

	class MealFactory final {
		typedef uint32_t Naming;
		typedef uint16_t Weight;

	private:
		MealStandart _oStandart;
		static std::shared_ptr<MealFactory> _instance;

	public:
		explicit MealFactory() {};
		MealFactory(const MealFactory&) = delete;
		MealFactory(MealFactory&&) = delete;
		MealFactory& operator= (const MealFactory&) = delete;
		MealFactory& operator= (MealFactory&&) = delete;

		void availableKeys_toStream(std::ostream& cout) noexcept;

		template <typename ...MealStandart>
		void supportedStandarts(const MealStandart&... standarts) {
			(_oStandart.merge(standarts), ...);
		}

		std::shared_ptr<Meal> getMeal(Naming naming, uint8_t level, Weight weight) noexcept;
		bool noAvailableKeys() { return _oStandart.noAvailableKeys(); };

	public:
		static MealFactory& instance() {
			if (not MealFactory::_instance) MealFactory::_instance = std::make_shared<MealFactory>();
			return *MealFactory::_instance;
		}
	};

}

