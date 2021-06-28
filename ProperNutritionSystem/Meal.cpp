#include "Meal.h"

namespace meal {

	Nutrients::Nutrients(const std::initializer_list<int16_t>& nutrients_list) noexcept {
		_nProteins = (nutrients_list.size() > 0) ? *nutrients_list.begin() : 0;
		_nFats = (nutrients_list.size() > 1) ? *(nutrients_list.begin() + 1) : 0;
		_nCarbohydrates = (nutrients_list.size() > 2) ? *(nutrients_list.begin() + 2) : 0;
	}

	Nutrients::Nutrients(const Nutrients& nutrients) noexcept {
		_nProteins = nutrients._nProteins;
		_nFats = nutrients._nFats;
		_nCarbohydrates = nutrients._nCarbohydrates;
	}

	Nutrients& Nutrients::operator= (const Nutrients& nutrients) noexcept {
		_nProteins = nutrients._nProteins;
		_nFats = nutrients._nFats;
		_nCarbohydrates = nutrients._nCarbohydrates;
		return *this;
	}

	Nutrients::Nutrients(Nutrients&& nutrients) noexcept {
		_nProteins = nutrients._nProteins;
		_nFats = nutrients._nFats;
		_nCarbohydrates = nutrients._nCarbohydrates;
	}

	Nutrients& Nutrients::operator= (Nutrients&& nutrients) noexcept {
		_nProteins = nutrients._nProteins;
		_nFats = nutrients._nFats;
		_nCarbohydrates = nutrients._nCarbohydrates;
		return *this;
	}

	void Nutrients::upgrade(uint16_t percents) noexcept {
		_nProteins = static_cast<uint16_t>
			(static_cast<double>(_nProteins)
				* static_cast<double>(percents) / 100
				);
		_nFats = static_cast<uint16_t>
			(static_cast<double>(_nFats)
				* static_cast<double>(percents) / 100
				);
		_nCarbohydrates = static_cast<uint16_t>
			(static_cast<double>(_nCarbohydrates)
				* static_cast<double>(percents) / 100
				);
	}

	std::string Nutrients::toString() const {
		std::stringstream ss;
		ss << "Proteins: " << this->proteins() << '\n';
		ss << "Fats: " << this->fats() << '\n';
		ss << "Carbohydrates: " << this->carbohydrates() << '\n';
		return ss.str();
	}

	void Nutrients::toStream(std::ostream& cout) noexcept {
		cout << "Proteins: " << this->proteins() << '\n';
		cout << "Fats: " << this->fats() << '\n';
		cout << "Carbohydrates: " << this->carbohydrates() << '\n';
	}

	MealVitamins::MealVitamins(const std::string& vitamins) noexcept {
		std::bitset<64> bits(vitamins);
		_bVitamins = static_cast<uint64_t>(bits.to_ullong());
	}

	MealVitamins::MealVitamins(const MealVitamins& vitamins) noexcept {
		_bVitamins = vitamins._bVitamins;
	}

	MealVitamins& MealVitamins::operator= (const MealVitamins& vitamins) noexcept {
		_bVitamins = vitamins._bVitamins;
		return *this;
	}

	MealVitamins::MealVitamins(MealVitamins&& vitamins) noexcept {
		_bVitamins = vitamins._bVitamins;
	}

	MealVitamins& MealVitamins::operator= (MealVitamins&& vitamins) noexcept {
		_bVitamins = vitamins._bVitamins;
		return *this;
	}

	uint64_t MealVitamins::validValue(uint64_t value) noexcept {
		return value > MealVitamins::MAX_VALUE ? MealVitamins::MAX_VALUE : value;
	}

	void MealVitamins::setA(uint64_t value) noexcept {
		uint64_t mask = MealVitamins::A;
		_bVitamins = ((_bVitamins & ~mask) | validValue(value) );
	}
	void MealVitamins::setB1(uint64_t value) noexcept {
		uint64_t mask = MealVitamins::B1;
		_bVitamins = ((_bVitamins & ~mask) | (validValue(value) << 4) );
	}
	void MealVitamins::setB2(uint64_t value) noexcept {
		uint64_t mask = MealVitamins::B2;
		_bVitamins = ((_bVitamins & ~mask) | (validValue(value) << 8) );
	}
	void MealVitamins::setB3(uint64_t value) noexcept {
		uint64_t mask = MealVitamins::B3;
		_bVitamins = ((_bVitamins & ~mask) | (validValue(value) << 12) );
	}

	void MealVitamins::setB5(uint64_t value) noexcept {
		uint64_t mask = MealVitamins::B5;
		_bVitamins = ((_bVitamins & ~mask) | (validValue(value) << 16) );
	}
	void MealVitamins::setB6(uint64_t value) noexcept {
		uint64_t mask = MealVitamins::B6;
		_bVitamins = ((_bVitamins & ~mask) | (validValue(value) << 20) );
	}
	void MealVitamins::setB7(uint64_t value) noexcept {
		uint64_t mask = MealVitamins::B7;
		_bVitamins = ((_bVitamins & ~mask) | (validValue(value) << 24) );
	}
	void MealVitamins::setB9(uint64_t value) noexcept {
		uint64_t mask = MealVitamins::B9;
		_bVitamins = ((_bVitamins & ~mask) | (validValue(value) << 28) );
	}

	void MealVitamins::setB12(uint64_t value) noexcept {
		uint64_t mask = MealVitamins::B12;
		_bVitamins = ((_bVitamins & ~mask) | (validValue(value) << 32) );
	}
	void MealVitamins::setC(uint64_t value) noexcept {
		uint64_t mask = MealVitamins::C;
		_bVitamins = ((_bVitamins & ~mask) | (validValue(value) << 36) );
	}
	void MealVitamins::setD(uint64_t value) noexcept {
		uint64_t mask = MealVitamins::D;
		_bVitamins = ((_bVitamins & ~mask) | (validValue(value) << 40) );
	}
	void MealVitamins::setE(uint64_t value) noexcept {
		uint64_t mask = MealVitamins::E;
		_bVitamins = ((_bVitamins & ~mask) | (validValue(value) << 44) );
	}

	void MealVitamins::setK(uint64_t value) noexcept {
		uint64_t mask = MealVitamins::K;
		_bVitamins = ((_bVitamins & ~mask) | (validValue(value) << 48) );
	}
	void MealVitamins::setN(uint64_t value) noexcept {
		uint64_t mask = MealVitamins::N;
		_bVitamins = ((_bVitamins & ~mask) | (validValue(value) << 52) );
	}
	void MealVitamins::setP(uint64_t value) noexcept {
		uint64_t mask = MealVitamins::P;
		_bVitamins = ((_bVitamins & ~mask) | (validValue(value) << 56) );
	}
	void MealVitamins::setU(uint64_t value) noexcept {
		uint64_t mask = MealVitamins::U;
		_bVitamins = ((_bVitamins & ~mask) | (validValue(value) << 60) );
	}

	uint64_t MealVitamins::getA() const noexcept {
		return _bVitamins & MealVitamins::A;
	}
	uint64_t MealVitamins::getB1() const noexcept {
		return (_bVitamins & MealVitamins::B1) >> 4;
	}
	uint64_t MealVitamins::getB2() const noexcept {
		return (_bVitamins & MealVitamins::B2) >> 8;
	}
	uint64_t MealVitamins::getB3() const noexcept {
		return (_bVitamins & MealVitamins::B3) >> 12;
	}

	uint64_t MealVitamins::getB5() const noexcept {
		return (_bVitamins & MealVitamins::B5) >> 16;
	}
	uint64_t MealVitamins::getB6() const noexcept {
		return (_bVitamins & MealVitamins::B6) >> 20;
	}
	uint64_t MealVitamins::getB7() const noexcept {
		return (_bVitamins & MealVitamins::B7) >> 24;
	}
	uint64_t MealVitamins::getB9() const noexcept {
		return (_bVitamins & MealVitamins::B9) >> 28;
	}

	uint64_t MealVitamins::getB12() const noexcept {
		return (_bVitamins & MealVitamins::B12) >> 32;
	}
	uint64_t MealVitamins::getC() const noexcept {
		return (_bVitamins & MealVitamins::C) >> 36;
	}
	uint64_t MealVitamins::getD() const noexcept {
		return (_bVitamins & MealVitamins::D) >> 40;
	}
	uint64_t MealVitamins::getE() const noexcept {
		return (_bVitamins & MealVitamins::E) >> 44;
	}

	uint64_t MealVitamins::getK() const noexcept {
		return (_bVitamins & MealVitamins::K) >> 48;
	}
	uint64_t MealVitamins::getN() const noexcept {
		return (_bVitamins & MealVitamins::N) >> 52;
	}
	uint64_t MealVitamins::getP() const noexcept {
		return (_bVitamins & MealVitamins::P) >> 56;
	}
	uint64_t MealVitamins::getU() const noexcept {
		return (_bVitamins & MealVitamins::U) >> 60;
	}

	void MealVitamins::toBitsetStream(std::ostream& cout) noexcept {
		cout << std::bitset<64>(_bVitamins) << '\n';
	}
	void MealVitamins::toUlonglongStream(std::ostream& cout) noexcept {
		cout << _bVitamins << '\n';
	}

	void MealVitamins::toStream(std::ostream& cout) noexcept {
		cout << "Vitamins: " << '\n';
		cout << "A:" << getA() << '\n';
		cout << "B1:" << getB1() << '\n';
		cout << "B2:" << getB2() << '\n';
		cout << "B3:" << getB3() << '\n';
		cout << "B5:" << getB5() << '\n';
		cout << "B6:" << getB6() << '\n';
		cout << "B7:" << getB7() << '\n';
		cout << "B9:" << getB9() << '\n';
		cout << "B12:" << getB12() << '\n';
		cout << "C:" << getC() << '\n';
		cout << "D:" << getD() << '\n';
		cout << "E:" << getE() << '\n';
		cout << "K:" << getK() << '\n';
		cout << "N:" << getN() << '\n';
		cout << "P:" << getP() << '\n';
		cout << "U:" << getU() << '\n';
	}

	void MealVitamins::upgrade(uint16_t percents) noexcept {
		uint64_t multiplier = static_cast<uint64_t>(percents / 100);
		this->setA(this->getA() * multiplier);
		this->setB1(this->getB1() * multiplier);
		this->setB2(this->getB2() * multiplier);
		this->setB3(this->getB3() * multiplier);

		this->setB5(this->getB5() * multiplier);
		this->setB6(this->getB6() * multiplier);
		this->setB7(this->getB7() * multiplier);
		this->setB9(this->getB9() * multiplier);

		this->setB12(this->getB12() * multiplier);
		this->setC(this->getC() * multiplier);
		this->setD(this->getD() * multiplier);
		this->setE(this->getE() * multiplier);

		this->setK(this->getK() * multiplier);
		this->setN(this->getN() * multiplier);
		this->setP(this->getP() * multiplier);
		this->setU(this->getU() * multiplier);
	}

	bool operator== (const MealVitamins& v1, const MealVitamins& v2) {
		return v1._bVitamins == v2._bVitamins;
	}

	bool operator!= (const MealVitamins& v1, const MealVitamins& v2) {
		return v1._bVitamins != v2._bVitamins;
	}

	/* Minerals */

	MealMinerals::MealMinerals(const std::string& minerals) noexcept {
		std::bitset<64> bits(minerals);
		_bMinerals = static_cast<uint64_t>(bits.to_ullong());
	}
	MealMinerals::MealMinerals(const MealMinerals& minerals) noexcept {
		_bMinerals = minerals._bMinerals;
	}
	MealMinerals& MealMinerals::operator= (const MealMinerals& minerals) noexcept {
		_bMinerals = minerals._bMinerals;
		return *this;
	}
	MealMinerals::MealMinerals(MealMinerals&& minerals) noexcept {
		_bMinerals = minerals._bMinerals;
	}
	MealMinerals& MealMinerals::operator= (MealMinerals&& minerals) noexcept {
		_bMinerals = minerals._bMinerals;
		return *this;
	}

	uint64_t MealMinerals::validValue(uint64_t value) noexcept {
		return value > MealMinerals::MAX_VALUE ? MealMinerals::MAX_VALUE : value;
	}

	void MealMinerals::setK(uint64_t value) noexcept {
		uint64_t mask = MealMinerals::K;
		_bMinerals = ((_bMinerals & ~mask) | validValue(value) );
	}
	void MealMinerals::setCl(uint64_t value) noexcept {
		uint64_t mask = MealMinerals::Cl;
		_bMinerals = ((_bMinerals & ~mask) | (validValue(value) << 4));
	}
	void MealMinerals::setNa(uint64_t value) noexcept {
		uint64_t mask = MealMinerals::Na;
		_bMinerals = ((_bMinerals & ~mask) | (validValue(value) << 8));
	}
	void MealMinerals::setCa(uint64_t value) noexcept {
		uint64_t mask = MealMinerals::Ca;
		_bMinerals = ((_bMinerals & ~mask) | (validValue(value) << 12));
	}

	void MealMinerals::setP(uint64_t value) noexcept {
		uint64_t mask = MealMinerals::P;
		_bMinerals = ((_bMinerals & ~mask) | (validValue(value) << 16));
	}
	void MealMinerals::setMg(uint64_t value) noexcept {
		uint64_t mask = MealMinerals::Mg;
		_bMinerals = ((_bMinerals & ~mask) | (validValue(value) << 20));
	}
	void MealMinerals::setZn(uint64_t value) noexcept {
		uint64_t mask = MealMinerals::Zn;
		_bMinerals = ((_bMinerals & ~mask) | (validValue(value) << 24));
	}
	void MealMinerals::setFe(uint64_t value) noexcept {
		uint64_t mask = MealMinerals::Fe;
		_bMinerals = ((_bMinerals & ~mask) | (validValue(value) << 28));
	}

	void MealMinerals::setMn(uint64_t value) noexcept {
		uint64_t mask = MealMinerals::Mn;
		_bMinerals = ((_bMinerals & ~mask) | (validValue(value) << 32));
	}
	void MealMinerals::setCu(uint64_t value) noexcept {
		uint64_t mask = MealMinerals::Cu;
		_bMinerals = ((_bMinerals & ~mask) | (validValue(value) << 36));
	}
	void MealMinerals::setI(uint64_t value) noexcept {
		uint64_t mask = MealMinerals::I;
		_bMinerals = ((_bMinerals & ~mask) | (validValue(value) << 40));
	}
	void MealMinerals::setSe(uint64_t value) noexcept {
		uint64_t mask = MealMinerals::Se;
		_bMinerals = ((_bMinerals & ~mask) | (validValue(value) << 44));
	}

	void MealMinerals::setMo(uint64_t value) noexcept {
		uint64_t mask = MealMinerals::Mo;
		_bMinerals = ((_bMinerals & ~mask) | (validValue(value) << 48));
	}
	void MealMinerals::setS(uint64_t value) noexcept {
		uint64_t mask = MealMinerals::S;
		_bMinerals = ((_bMinerals & ~mask) | (validValue(value) << 52));
	}
	void MealMinerals::setCr(uint64_t value) noexcept {
		uint64_t mask = MealMinerals::Cr;
		_bMinerals = ((_bMinerals & ~mask) | (validValue(value) << 56));
	}
	void MealMinerals::setF(uint64_t value) noexcept {
		uint64_t mask = MealMinerals::F;
		_bMinerals = ((_bMinerals & ~mask) | (validValue(value) << 60));
	}

	uint64_t MealMinerals::getK() const noexcept {
		return _bMinerals & MealMinerals::K;
	}
	uint64_t MealMinerals::getCl() const noexcept {
		return (_bMinerals & MealMinerals::Cl) >> 4;
	}
	uint64_t MealMinerals::getNa() const noexcept {
		return (_bMinerals & MealMinerals::Na) >> 8;
	}
	uint64_t MealMinerals::getCa() const noexcept {
		return (_bMinerals & MealMinerals::Ca) >> 12;
	}

	uint64_t MealMinerals::getP() const noexcept {
		return (_bMinerals & MealMinerals::P) >> 16;
	}
	uint64_t MealMinerals::getMg() const noexcept {
		return (_bMinerals & MealMinerals::Mg) >> 20;
	}
	uint64_t MealMinerals::getZn() const noexcept {
		return (_bMinerals & MealMinerals::Zn) >> 24;
	}
	uint64_t MealMinerals::getFe() const noexcept {
		return (_bMinerals & MealMinerals::Fe) >> 28;
	}

	uint64_t MealMinerals::getMn() const noexcept {
		return (_bMinerals & MealMinerals::Mn) >> 32;
	}
	uint64_t MealMinerals::getCu() const noexcept {
		return (_bMinerals & MealMinerals::Cu) >> 36;
	}
	uint64_t MealMinerals::getI() const noexcept {
		return (_bMinerals & MealMinerals::I) >> 40;
	}
	uint64_t MealMinerals::getSe() const noexcept {
		return (_bMinerals & MealMinerals::Se) >> 44;
	}

	uint64_t MealMinerals::getMo() const noexcept {
		return (_bMinerals & MealMinerals::Mo) >> 48;
	}
	uint64_t MealMinerals::getS() const noexcept {
		return (_bMinerals & MealMinerals::S) >> 52;
	}
	uint64_t MealMinerals::getCr() const noexcept {
		return (_bMinerals & MealMinerals::Cr) >> 56;
	}
	uint64_t MealMinerals::getF() const noexcept {
		return (_bMinerals & MealMinerals::F) >> 60;
	}

	void MealMinerals::toBitsetStream(std::ostream& cout) noexcept {
		cout << std::bitset<64>(_bMinerals) << '\n';
	}
	void MealMinerals::toUlonglongStream(std::ostream& cout) noexcept {
		cout << _bMinerals << '\n';
	}

	void MealMinerals::toStream(std::ostream& cout) noexcept {
		cout << "Minerals: " << '\n';
		cout << "K:" << getK() << '\n';
		cout << "Cl:" << getCl() << '\n';
		cout << "Na:" << getNa() << '\n';
		cout << "Ca:" << getCa() << '\n';
		cout << "P:" << getP() << '\n';
		cout << "Mg:" << getMg() << '\n';
		cout << "Zn:" << getZn() << '\n';
		cout << "Fe:" << getFe() << '\n';
		cout << "Mn:" << getMn() << '\n';
		cout << "Cu:" << getCu() << '\n';
		cout << "I:" << getI() << '\n';
		cout << "Se:" << getSe() << '\n';
		cout << "Mo:" << getMo() << '\n';
		cout << "S:" << getS() << '\n';
		cout << "Cr:" << getCr() << '\n';
		cout << "F:" << getF() << '\n';
	}

	void MealMinerals::upgrade(uint16_t percents) noexcept {
		uint64_t multiplier = static_cast<uint64_t>(percents / 100);
		this->setK(this->getK() * multiplier);
		this->setCl(this->getCl() * multiplier);
		this->setNa(this->getNa() * multiplier);
		this->setCa(this->getCa() * multiplier);

		this->setP(this->getP() * multiplier);
		this->setMg(this->getMg() * multiplier);
		this->setZn(this->getZn() * multiplier);
		this->setFe(this->getFe() * multiplier);

		this->setMn(this->getMn() * multiplier);
		this->setCu(this->getCu() * multiplier);
		this->setI(this->getI() * multiplier);
		this->setSe(this->getSe() * multiplier);

		this->setMo(this->getMo() * multiplier);
		this->setS(this->getS() * multiplier);
		this->setCr(this->getCr() * multiplier);
		this->setF(this->getF() * multiplier);
	}

	bool operator== (const MealMinerals& m1, const MealMinerals& m2) {
		return m1._bMinerals == m2._bMinerals;
	}
	bool operator!= (const MealMinerals& m1, const MealMinerals& m2) {
		return m1._bMinerals != m2._bMinerals;
	}

	/* Taste Qualities */

	TasteQualities::TasteQualities(const std::string& qualities) noexcept {
		std::bitset<16> bits(qualities);
		_bQualities = static_cast<uint16_t>(bits.to_ulong());
	}

	TasteQualities::TasteQualities(const TasteQualities& qualities) noexcept {
		_bQualities = qualities._bQualities;
	}

	TasteQualities& TasteQualities::operator= (const TasteQualities& qualities) noexcept {
		_bQualities = qualities._bQualities;
		return *this;
	}

	TasteQualities::TasteQualities(TasteQualities&& qualities) noexcept {
		_bQualities = qualities._bQualities;
	}

	TasteQualities& TasteQualities::operator= (TasteQualities&& qualities) noexcept {
		_bQualities = qualities._bQualities;
		return *this;
	}

	bool operator== (const TasteQualities& q1, const TasteQualities& q2) {
		return q1._bQualities == q2._bQualities;
	}

	bool operator!= (const TasteQualities& q1, const TasteQualities& q2) {
		return q1._bQualities != q2._bQualities;
	}

	void TasteQualities::update(uint16_t value) noexcept {
		_bQualities = value;
	}

	uint16_t TasteQualities::validValue(uint16_t value) noexcept {
		return value > TasteQualities::MAX_VALUE ? TasteQualities::MAX_VALUE : value;
	}

	void TasteQualities::setSalty(uint16_t value) {
		uint16_t mask = TasteQualities::Salty;
		_bQualities = ( (_bQualities & ~mask) | validValue(value) ) ;
	}
	void TasteQualities::setAcidic(uint16_t value) {
		uint16_t mask = TasteQualities::Acidic;
		_bQualities = ( (_bQualities & ~mask) | (validValue(value) << 2) );
	}
	void TasteQualities::setSugary(uint16_t value) {
		uint16_t mask = TasteQualities::Sugary;
		_bQualities = ( (_bQualities & ~mask) | (validValue(value) << 4) );
	}
	void TasteQualities::setBitter(uint16_t value) {
		uint16_t mask = TasteQualities::Bitter;
		_bQualities = ( (_bQualities & ~mask) | (validValue(value) << 6));
	}
	void TasteQualities::setFatty(uint16_t value) {
		uint16_t mask = TasteQualities::Fatty;
		_bQualities = ( (_bQualities & ~mask) | (validValue(value) << 8));
	}
	void TasteQualities::setStiff(uint16_t value) {
		uint16_t mask = TasteQualities::Stiff;
		_bQualities = ( (_bQualities & ~mask) | (validValue(value) << 10));
	}
	void TasteQualities::setHarsh(uint16_t value) {
		uint16_t mask = TasteQualities::Harsh;
		_bQualities = ( (_bQualities & ~mask) | (validValue(value) << 12));
	}
	void TasteQualities::setHot(uint16_t value) {
		uint16_t mask = TasteQualities::Hot;
		_bQualities = ( (_bQualities & ~mask) | (validValue(value) << 14));
	}

	uint16_t TasteQualities::getSalty() {
		return _bQualities & TasteQualities::Salty;
	}
	uint16_t TasteQualities::getAcidic() {
		return (_bQualities & TasteQualities::Acidic) >> 2;
	}
	uint16_t TasteQualities::getSugary() {
		return (_bQualities & TasteQualities::Sugary) >> 4;
	}
	uint16_t TasteQualities::getBitter() {
		return (_bQualities & TasteQualities::Bitter) >> 6;
	}
	uint16_t TasteQualities::getFatty() {
		return (_bQualities & TasteQualities::Fatty) >> 8;
	}
	uint16_t TasteQualities::getStiff() {
		return (_bQualities & TasteQualities::Stiff) >> 10;
	}
	uint16_t TasteQualities::getHarsh() {
		return (_bQualities & TasteQualities::Harsh) >> 12;
	}
	uint16_t TasteQualities::getHot() {
		return (_bQualities & TasteQualities::Hot) >> 14;
	}

	void TasteQualities::toBitsetStream(std::ostream& cout) noexcept {
		cout << std::bitset<16>(_bQualities) << '\n';
	}
	void TasteQualities::toUlongStream(std::ostream& cout) noexcept {
		cout << _bQualities << '\n';
	}

	void TasteQualities::toStream(std::ostream& cout) noexcept {
		cout << "TasteQualities: " << '\n';
		cout << getStatus(TasteQualities::Salty, getSalty()) << '\n';
		cout << getStatus(TasteQualities::Acidic, getAcidic()) << '\n';
		cout << getStatus(TasteQualities::Sugary, getSugary()) << '\n';
		cout << getStatus(TasteQualities::Bitter, getBitter()) << '\n';
		cout << getStatus(TasteQualities::Fatty, getFatty()) << '\n';
		cout << getStatus(TasteQualities::Stiff, getStiff()) << '\n';
		cout << getStatus(TasteQualities::Harsh, getHarsh()) << '\n';
		cout << getStatus(TasteQualities::Hot, getHot()) << '\n';
	}

	std::string TasteQualities::getStatus(uint16_t quality, uint16_t status) {
		std::stringstream ss;
		switch (status) {
		case TasteQualities::None:			ss	<< "none";		break;
		case TasteQualities::Abstinently:	ss	<< "absinently";	break;
		case TasteQualities::Saturated:		ss	<< "saturated";	break;
		case TasteQualities::Redundantly:	ss	<< "reduntantly";break;
		}
		ss << ' ';
		switch (quality) {
		case TasteQualities::Salty:			ss	<<	"salty";	break;
		case TasteQualities::Acidic:		ss	<<	"acidic";	break;
		case TasteQualities::Sugary:		ss	<<	"sugary";	break;
		case TasteQualities::Bitter:		ss	<<	"bitter";	break;
		case TasteQualities::Fatty:			ss	<<	"fatty";	break;
		case TasteQualities::Stiff:			ss	<<	"stiff";	break;
		case TasteQualities::Harsh:			ss	<<	"harsh";	break;
		case TasteQualities::Hot:			ss	<<	"hot";		break;
		}
		return ss.str();
	}


	MealDate::MealDate(const MealDate& date) noexcept {
		_tInitialDate = date._tInitialDate;
		_tExpritationDate = date._tExpritationDate;
	}

	MealDate& MealDate::operator= (const MealDate& date) noexcept {
		_tInitialDate = date._tInitialDate;
		_tExpritationDate = date._tExpritationDate;
		return *this;
	}

	MealDate::MealDate(MealDate&& date) noexcept {
		_tInitialDate = date._tInitialDate;
		_tExpritationDate = date._tExpritationDate;
	}

	MealDate& MealDate::operator= (MealDate&& date) noexcept {
		_tInitialDate = date._tInitialDate;
		_tExpritationDate = date._tExpritationDate;
		return *this;
	}

	MealDate::MealDate(const std::initializer_list<time_t>& list) noexcept {
		_tInitialDate = (list.size() > 0)
			? *list.begin()
			: time(NULL);
		_tExpritationDate = (list.size() > 1)
			? *(list.begin() + 1)
			: time(NULL);
	}

	MealDate::MealDate(const std::initializer_list<time_point>& list) noexcept {
		_tInitialDate = (list.size() > 0)
			? std::chrono::system_clock::to_time_t (*list.begin())
			: time(NULL);
		_tExpritationDate = (list.size() > 1)
			? std::chrono::system_clock::to_time_t (*(list.begin() + 1))
			: time(NULL);
	}

	void MealDate::update(time_t newDate) {
		time_t tTimeDifference = newDate - _tInitialDate;
		_tExpritationDate += tTimeDifference;
		_tInitialDate = newDate;
	}

	std::string MealDate::toString() const {
		std::stringstream ss;
		ss << "Initial Date: " << utilities::time_stamp(_tInitialDate) << '\n';
		ss << "Expritation Date: " << utilities::time_stamp(_tExpritationDate) << '\n';
		return ss.str();
	}

	void  MealDate::toStream(std::ostream& cout) noexcept {
		cout << "Initial Date: " << utilities::time_stamp(_tInitialDate) << '\n';
		cout << "Expritation Date: " << utilities::time_stamp(_tExpritationDate) << '\n';
	}

	StorageTemperature::StorageTemperature(const std::initializer_list<int8_t>& list) noexcept {
		_n8Current = (list.size() > 0)
			? *list.begin()
			: 0;
		_n8Reccomended = (list.size() > 1)
			? *(list.begin() + 1)
			: 0;
		_n8PermissibleDifference = (list.size() > 2)
			? *(list.begin() + 2)
			: 0;
	}

	StorageTemperature::StorageTemperature(const StorageTemperature& temperature) noexcept {
		_n8Current = temperature._n8Current;
		_n8Reccomended = temperature._n8Reccomended;
		_n8PermissibleDifference = temperature._n8PermissibleDifference;
	}

	StorageTemperature& StorageTemperature::operator= (const StorageTemperature& temperature) noexcept {
		_n8Current = temperature._n8Current;
		_n8Reccomended = temperature._n8Reccomended;
		_n8PermissibleDifference = temperature._n8PermissibleDifference;
		return *this;
	}

	StorageTemperature::StorageTemperature(StorageTemperature&& temperature) noexcept {
		_n8Current = temperature._n8Current;
		_n8Reccomended = temperature._n8Reccomended;
		_n8PermissibleDifference = temperature._n8PermissibleDifference;
	}

	StorageTemperature& StorageTemperature::operator= (StorageTemperature&& temperature) noexcept {
		_n8Current = temperature._n8Current;
		_n8Reccomended = temperature._n8Reccomended;
		_n8PermissibleDifference = temperature._n8PermissibleDifference;
		return *this;
	}

	std::string StorageTemperature::toString() const {
		std::stringstream ss;
		ss << "Current storage temperature: " << (int)_n8Current << " C" << '\n';
		ss << "Recommended storage temperature: " << (int)_n8Reccomended << " C" << '\n';
		ss << "Permissible temperature difference: " << (int)_n8PermissibleDifference << " C" << '\n';
		return ss.str();
	}

	void  StorageTemperature::toStream(std::ostream& cout) noexcept {
		cout << "Current storage temperature: " << (int)_n8Current << " C" << '\n';
		cout << "Recommended storage temperature: " << (int)_n8Reccomended << " C" << '\n';
		cout << "Permissible temperature difference: " << (int)_n8PermissibleDifference << " C" << '\n';
	}

	MealProperties::MealProperties(Nutrients&& n, TasteQualities&& q, Calories c, Moisture m, MealDate&& d, StorageTemperature&& t)	noexcept :
		_oNutrients(std::move(n)), _oQualities(std::move(q)), _nCalories(c), _nMoisture(m), _oMealDate(std::move(d)), _oTemperature(std::move(t))	{}

	MealProperties::MealProperties(const Nutrients& n, const TasteQualities& q, Calories c, Moisture m, const MealDate& d, const StorageTemperature& t) noexcept :
		_oNutrients(n), _oQualities(q), _nCalories(c), _nMoisture(m), _oMealDate(d), _oTemperature(t) {}

	void MealProperties::initNutrients(Nutrients&& nutrients) noexcept {
		_oNutrients = nutrients;
	};
	void MealProperties::initTasteQualities(TasteQualities&& qualities) noexcept {
		_oQualities = qualities;
	}
	void MealProperties::initCalories(Calories calories) noexcept {
		_nCalories = calories;
	}
	void MealProperties::initMoisture(Moisture moisture) noexcept {
		_nMoisture = moisture;
	}
	void MealProperties::initDate(MealDate&& date) noexcept {
		_oMealDate = date;
	}
	void MealProperties::initTemperature(StorageTemperature&& temperature) noexcept {
		_oTemperature = temperature;
	}
	void MealProperties::initVitamins(MealVitamins&& vitamins) noexcept {
		_oVitamins = vitamins;
	}
	void MealProperties::initMinerals(MealMinerals&& minerals) noexcept {
		_oMinerals = minerals;
	}

	MealProperties::MealProperties(const MealProperties& properties) noexcept {
		if (properties._oNutrients) this->_oNutrients = *properties._oNutrients;
		if (properties._oQualities) this->_oQualities = *properties._oQualities;
		this->_nCalories = properties._nCalories;
		this->_nMoisture = properties._nMoisture;
		if (properties._oMealDate) this->_oMealDate = *properties._oMealDate;
		if (properties._oTemperature) this->_oTemperature = *properties._oTemperature;
		if (properties._oVitamins) this->_oVitamins = *properties._oVitamins;
		if (properties._oMinerals) this->_oMinerals = *properties._oMinerals;
	}

	MealProperties& MealProperties::operator= (const MealProperties& properties) noexcept {
		if (properties._oNutrients) this->_oNutrients = *properties._oNutrients;
		if (properties._oQualities) this->_oQualities = *properties._oQualities;
		this->_nCalories = properties._nCalories;
		this->_nMoisture = properties._nMoisture;
		if (properties._oMealDate) this->_oMealDate = *properties._oMealDate;
		if (properties._oTemperature) this->_oTemperature = *properties._oTemperature;
		if (properties._oVitamins) this->_oVitamins = *properties._oVitamins;
		if (properties._oMinerals) this->_oMinerals = *properties._oMinerals;
		return *this;
	}

	MealProperties::MealProperties(MealProperties&& properties) noexcept {
		if (properties._oNutrients) this->_oNutrients = std::move(*properties._oNutrients);
		if (properties._oQualities) this->_oQualities = *properties._oQualities;
		this->_nCalories = properties._nCalories;
		this->_nMoisture = properties._nMoisture;
		if (properties._oMealDate) this->_oMealDate = std::move(*properties._oMealDate);
		if (properties._oTemperature) this->_oTemperature = std::move(*properties._oTemperature);
		if (properties._oVitamins) this->_oVitamins = std::move(*properties._oVitamins);
		if (properties._oMinerals) this->_oMinerals = std::move(*properties._oMinerals);
	}

	MealProperties& MealProperties::operator= (MealProperties&& properties) noexcept {
		if (properties._oNutrients) this->_oNutrients = std::move(*properties._oNutrients);
		if (properties._oQualities) this->_oQualities = *properties._oQualities;
		this->_nCalories = properties._nCalories;
		this->_nMoisture = properties._nMoisture;
		if (properties._oMealDate) this->_oMealDate = std::move(*properties._oMealDate);
		if (properties._oTemperature) this->_oTemperature = std::move(*properties._oTemperature);
		if (properties._oVitamins) this->_oVitamins = std::move(*properties._oVitamins);
		if (properties._oMinerals) this->_oMinerals = std::move(*properties._oMinerals);
		return *this;
	}

	void MealProperties::setTasteQualities(uint16_t value) {
		if (_oQualities) (*_oQualities).update(value);
	}

	bool MealProperties::validateTasteQualities(uint16_t value) {
		return _oQualities ? (*_oQualities) == TasteQualities{ value } : false;
	}
	bool MealProperties::validateVitamins(uint64_t value) {
		return _oVitamins ? (*_oVitamins) == MealVitamins{ value } : false;
	}
	bool MealProperties::validateMinerals(uint64_t value) {
		return _oMinerals ? (*_oMinerals) == MealMinerals{ value } : false;
	}

	void MealProperties::upgradeCalories(uint16_t percents) noexcept {
		double multiplier = static_cast<double>(percents) / 100;
		uint32_t value = static_cast<uint32_t>(_nCalories * multiplier);
		_nCalories = value < UINT16_MAX ? value : UINT16_MAX;
	}
	void MealProperties::upgradeMoisture(uint16_t percents) noexcept {
		double multiplier = static_cast<double>(percents) / 100;
		uint32_t value = static_cast<uint32_t>(_nMoisture * multiplier);
		_nMoisture = value < UINT16_MAX ? value : UINT16_MAX;
	}

	void MealProperties::upgradeNutrients(uint16_t percents) noexcept {
		if (_oNutrients) (*_oNutrients).upgrade(percents);
	}

	void MealProperties::upgradeVitamins(uint16_t percents) noexcept {
		if (_oVitamins) (*_oVitamins).upgrade(percents);
	}

	void MealProperties::upgradeMinerals(uint16_t percents) noexcept {
		if (_oMinerals) (*_oMinerals).upgrade(percents);
	}


	void MealProperties::updateDate(time_t date) {
		if (_oMealDate) (*_oMealDate).update(date);
	}

	void MealProperties::toStream(std::ostream& cout) noexcept {
		if (_oNutrients) (*_oNutrients).toStream(cout);
		if (_oQualities) (*_oQualities).toStream(cout);
		cout << "Calories: " << _nCalories << '\n';
		cout << "Moisture: " << _nMoisture << '\n';
		if (_oMealDate) (*_oMealDate).toStream(cout);
		if (_oTemperature) (*_oTemperature).toStream(cout);
		if (_oVitamins) (*_oVitamins).toStream(cout);
		if (_oMinerals) (*_oMinerals).toStream(cout);
	}

	std::vector<std::shared_ptr<MealMode>>& MealPropertiesModifier::getLevelModes(uint8_t level) {
		switch (level) {
		case 1: return level_1_modes;
		case 2: return level_2_modes;
		case 3: return level_3_modes;
		default: return level_0_modes;
		}
	}

	MealPropertiesModifier::MealPropertiesModifier(const MealProperties& prototype) {
		_oPropertiesPrototype = prototype;
	}

	MealPropertiesModifier::MealPropertiesModifier(MealProperties&& prototype) {
		_oPropertiesPrototype = prototype;
	}

	void MealPropertiesModifier::addMode(std::shared_ptr<MealMode> modePtr, uint8_t level) {
		std::vector<std::shared_ptr<MealMode>>& levelModes = getLevelModes(level);
		levelModes.push_back(modePtr);
	}

	void MealPropertiesModifier::modify(uint8_t level, std::shared_ptr<MealProperties> propertiesPtr) {
		if (not propertiesPtr) return;
		std::vector<std::shared_ptr<MealMode>>& levelModes = getLevelModes(level);
		for (auto& modePtr : levelModes)
			if (modePtr) (*modePtr).modify(propertiesPtr);
	}

	void TasteQualities_MealMode::modify(std::shared_ptr<MealProperties> propertiesPtr) {
		if (not propertiesPtr) return;
		(*propertiesPtr).setTasteQualities(_nValue);
	}

	std::shared_ptr<MealMode> LevelDowngrade_MealMode::level_3_mode
		= std::make_shared<LevelDowngrade_MealMode>(LevelDowngrade_MealMode(55));

	std::shared_ptr<MealMode> LevelDowngrade_MealMode::level_2_mode
		= std::make_shared<LevelDowngrade_MealMode>(LevelDowngrade_MealMode(70));

	std::shared_ptr<MealMode> LevelDowngrade_MealMode::level_1_mode
		= std::make_shared<LevelDowngrade_MealMode>(LevelDowngrade_MealMode(85));

	void LevelDowngrade_MealMode::modify(std::shared_ptr<MealProperties> propertiesPtr) {
		if (not propertiesPtr) return;
		(*propertiesPtr).upgradeCalories(_nValue);
		(*propertiesPtr).upgradeMoisture(_nValue);
		(*propertiesPtr).upgradeNutrients(_nValue);
	}

	void MealWeight_MealMode::modify(std::shared_ptr<MealProperties> propertiesPtr) {
		if (not propertiesPtr) return;
		(*propertiesPtr).upgradeCalories(_nValue);
		(*propertiesPtr).upgradeMoisture(_nValue);
		(*propertiesPtr).upgradeNutrients(_nValue);
		(*propertiesPtr).upgradeVitamins(_nValue);
		(*propertiesPtr).upgradeMinerals(_nValue);
	}

	MealDate_MealMode::MealDate_MealMode(time_point currentDate) noexcept : MealMode(0) {
		_tCurrentDate = std::chrono::system_clock::to_time_t(currentDate);
	}

	void MealDate_MealMode::modify(std::shared_ptr<MealProperties> propertiesPtr) {
		if (not propertiesPtr) return;
		(*propertiesPtr).updateDate(_tCurrentDate);
	}

	std::shared_ptr<MealProperties> MealPropertiesModifier::getModifiedMealProperties(uint8_t level) {
		if (not _oPropertiesPrototype) return nullptr;
		MealProperties properties = *_oPropertiesPrototype;
		std::shared_ptr<MealProperties> propertyPtr = std::make_shared<MealProperties>(properties);
		modify(level, propertyPtr);
		return propertyPtr;
	}

	std::shared_ptr<MealPropertiesModifier> MealStandart::getModifier(Naming naming) noexcept {
		auto search = _mStandartMap.find(naming);
		if (search == _mStandartMap.end()) return nullptr;
		std::function<std::shared_ptr<MealPropertiesModifier>()> mealProducer = search->second;
		return mealProducer();
	}

	void MealStandart::merge(const MealStandart& standart) noexcept {
		_mStandartMap.insert(standart._mStandartMap.begin(), standart._mStandartMap.end());
	}

	void MealStandart::availableKeys_toStream(std::ostream& cout) noexcept {
		for (const auto& [key, value] : _mStandartMap)
			cout << key << '\n';
	}

	bool Meal::validateTasteQualities(uint16_t value) {
		return _pProperties ? (*_pProperties).validateTasteQualities(value) : false;
	}
	bool Meal::validateVitamins(uint64_t value) {
		return _pProperties ? (*_pProperties).validateVitamins(value) : false;
	}
	bool Meal::validateMinerals(uint64_t value) {
		return _pProperties ? (*_pProperties).validateMinerals(value) : false;
	}

	void Meal::toStream(std::ostream& cout) noexcept {
		if (_pProperties) (*_pProperties).toStream(cout);
	}

	std::shared_ptr<MealFactory> MealFactory::_instance = nullptr;

	void MealFactory::availableKeys_toStream(std::ostream& cout) noexcept {
		_oStandart.availableKeys_toStream(cout);
	}

	std::shared_ptr<Meal> MealFactory::getMeal(Naming naming, uint8_t level, Weight weight) noexcept {
		std::shared_ptr<MealPropertiesModifier> modifierPtr = _oStandart.getModifier(naming);
		if (not modifierPtr) return nullptr;
		std::shared_ptr<MealProperties> propertiesPtr = (*modifierPtr).getModifiedMealProperties(level);
		if (not propertiesPtr) return nullptr;
		MealWeight_MealMode currentWeightMode{ weight };
		currentWeightMode.modify(propertiesPtr);
		auto now = std::chrono::system_clock::now();
		MealDate_MealMode currentDateMode{ now };
		currentDateMode.modify(propertiesPtr);
		Meal meal{ propertiesPtr };
		return std::make_shared<Meal>(meal);
	}


	/*


	MealProperties::MealProperties(MealProperties const &meal) noexcept {
		_oNutrients = std::make_shared<Nutrients>(meal._oNutrients);
		_nCalories = meal._nCalories;
		_tExpritationDate = meal._tExpritationDate;
		_nStorageTemperature = meal._nStorageTemperature;
		_tInitialDate = meal._tInitialDate;
		_nCurrentStorageTemperature = meal._nCurrentStorageTemperature;
	}

	MealProperties& MealProperties::operator= (MealProperties const &meal) noexcept {
		_oNutrients = std::make_shared<Nutrients>(meal._oNutrients);
		_nCalories = meal._nCalories;
		_tExpritationDate = meal._tExpritationDate;
		_nStorageTemperature = meal._nStorageTemperature;
		_tInitialDate = meal._tInitialDate;
		_nCurrentStorageTemperature = meal._nCurrentStorageTemperature;
	}

	Meal::Meal(const MealStandart& standart, Naming naming, Weight weight, StorageTemperature currentTemperature) noexcept {
		std::optional<MealProperties> meal = standart.getMeal(naming);
		if (not meal) {
			this->_nNaming = 0;
			this->_nWeight = 0;
			this->_oMealProperties = std::make_shared<MealProperties>(MealProperties());
		}
		else {
			const MealProperties& standartProperties = *meal;

			Weight currentWeight = weight / 100;

			int16_t currentProteins = standartProperties.nutrients().proteins() * currentWeight;
			int16_t currentFats = standartProperties.nutrients().fats() * currentWeight;
			int16_t currentCarbohydrates = standartProperties.nutrients().carbohydrates() * currentWeight;
			int16_t currentVitamines = standartProperties.nutrients().vitamines() * currentWeight;
			Nutrients currentNutrients{ currentProteins, currentFats, currentCarbohydrates, currentVitamines };

			Calories currentCalories = standartProperties.calories() * currentWeight;

			time_t initialDate = time(NULL);
			time_t offset = initialDate - standartProperties.initialDate();
			time_t expritationDate = standartProperties.expritationDate() + offset;

			StorageTemperature storageTemperature = standartProperties.storageTemperature();

			this->_oMealProperties = std::make_shared<MealProperties> (MealProperties(
				currentNutrients,
				currentCalories,
				expritationDate,
				storageTemperature,
				initialDate,
				currentTemperature
				));
		}
	}

	MealFactory::MealFactory(StandartMealFactory&& standartFactory) {
		std::optional<MealStandart> standartOpt = standartFactory.getStandart();
		if (standartOpt ) this->_oStandart = *standartOpt;
	}

	Meal&& MealFactory::getMeal(Naming naming, Weight weight, StorageTemperature temperature) {
		Meal meal(this->_oStandart, naming, weight, temperature);
		return std::move(meal);
	};

	*/
}