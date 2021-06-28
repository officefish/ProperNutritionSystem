// ProperNutritionSystem.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>

#include "Meal.h"
#include <random>


int main()
{

    //meal::TasteQualities qualities{ "110000001100" };
   // qualities.toStream(std::cout);
    //qualities.toBitsetStream(std::cout);
   // qualities.toUlongStream(std::cout);

    std::random_device rd;
    std::mt19937 generator(rd());

    std::uniform_int_distribution<unsigned long long> distribution(
        std::numeric_limits<std::uint64_t>::min(),
        std::numeric_limits<std::uint64_t>::max()
    );
    uint64_t dice_roll = distribution(generator);  // generates number in the range 1..

    //meal::MealMinerals m{ 0 };
    //m.setNa(20);
    //m.toStream(std::cout);

    /*
    meal::MealMinerals m1{ dice_roll };
    m1.toUlonglongStream(std::cout);
    m1.toStream(std::cout);

    meal::MealMinerals m2{ 0 };
    m2.setK(m1.getK());
    m2.setCl(m1.getCl());
    m2.setNa(m1.getNa());
    m2.setCa(m1.getCa());

    m2.setP(m1.getP());
    m2.setMg(m1.getMg());
    m2.setZn(m1.getZn());
    m2.setFe(m1.getFe());

    m2.setMn(m1.getMn());
    m2.setCu(m1.getCu());
    m2.setI(m1.getI());
    m2.setSe(m1.getSe());

    m2.setMo(m1.getMo());
    m2.setS(m1.getS());
    m2.setCr(m1.getCr());
    m2.setF(m1.getF());

    m2.toUlonglongStream(std::cout);
    //m2.toStream(std::cout);

    std::cout << std::boolalpha << (m1 == m2) << std::endl;
    */


    //meal::MealVitamins v1{ dice_roll };
    //v1.toUlonglongStream(std::cout);
    //v1.toStream(std::cout);
    /*
    meal::MealVitamins vitamins{ 0 };
    vitamins.setA(0);
    vitamins.setB1(1);
    vitamins.setB2(1);
    vitamins.setB3(1);

    vitamins.setB5(3);
    vitamins.setB6(1);
    vitamins.setB7(0);
    vitamins.setB9(1);

    vitamins.setB12(0);
    vitamins.setC(1);
    vitamins.setD(0);
    vitamins.setE(1);

    vitamins.setK(1);
    vitamins.setN(0);
    vitamins.setP(1);
    vitamins.setU(0);

    vitamins.toUlonglongStream(std::cout);


    meal::MealMinerals minerals{ 0 };
    minerals.setK(1);
    minerals.setCl(0);
    minerals.setNa(1);
    minerals.setCa(1);
    minerals.setP(1);
    minerals.setMg(1);
    minerals.setZn(1);
    minerals.setFe(1);
    minerals.setMn(1);
    minerals.setCu(1);
    minerals.setI(2);
    minerals.setSe(1);
    minerals.setMo(1);
    minerals.setS(0);
    minerals.setCr(1);
    minerals.setF(1);
    minerals.toUlonglongStream(std::cout);
    //minerals.toStream(std::cout);

    */

    //v2.toStream(std::cout);

    //std::cout << v1.getA() << std::endl;
    //std::cout << v2.getA() << std::endl;
    //std::cout << std::boolalpha << (v1 == v2) << std::endl;


    meal::EarlierMiddleAges_Temperate_MealStandart tStandart{};
    meal::EarlierMiddleAges_SubTropic_MealStandart stStandart{};

    auto & mealFactory = meal::MealFactory::instance();
    mealFactory.supportedStandarts(tStandart, stStandart);

    std::shared_ptr<meal::Meal> ptr = mealFactory.getMeal(14010101, 2, 1000);
    if (ptr) (*ptr).toStream(std::cout);


    //std::shared_ptr<meal::MealProperties> ptr = standart.getMealProperties(14010101);
    //if (ptr) (*ptr).toStream(std::cout);
    //std::cout << std::boolalpha << ptr << '\n';

    //meal::MealFactory _oMealFactory{ meal::MedivialStandartMealFactory() };
    //meal::Meal apple = _oMealFactory.getMeal(1, 100, 20);
    //std::cout << apple.toString();

    //std::cout << "Hello World!\n";
}
