#include <gtest/gtest.h>
#include <sstream>
#include <cmath>
#include "point.h"
#include "figure.h"
#include "trapezoid.h"
#include "rhombus.h"
#include "pentagon.h"
#include "array.h"

// Тесты для класса Point
TEST(PointTest, DefaultConstructor) {
    Point p;
    EXPECT_DOUBLE_EQ(p.x, 0.0);
    EXPECT_DOUBLE_EQ(p.y, 0.0);
}

TEST(PointTest, ParameterizedConstructor) {
    Point p(3.5, 2.7);
    EXPECT_DOUBLE_EQ(p.x, 3.5);
    EXPECT_DOUBLE_EQ(p.y, 2.7);
}

TEST(PointTest, EqualityOperator) {
    Point p1(1.0, 2.0);
    Point p2(1.0, 2.0);
    Point p3(1.0, 3.0);
    
    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
}

TEST(PointTest, StreamOperators) {
    Point p1(1.5, 2.5);
    std::stringstream ss;
    ss << p1;
    
    // Проверяем формат вывода
    std::string output = ss.str();
    EXPECT_NE(output.find("1.5"), std::string::npos);
    EXPECT_NE(output.find("2.5"), std::string::npos);
    EXPECT_NE(output.find("("), std::string::npos);
    EXPECT_NE(output.find(")"), std::string::npos);
    
    // Для ввода используем простой формат
    std::stringstream ss2;
    ss2 << "3.0 4.0";
    Point p2;
    ss2 >> p2;
    
    EXPECT_DOUBLE_EQ(p2.x, 3.0);
    EXPECT_DOUBLE_EQ(p2.y, 4.0);
}

// Тесты для класса Figure (через Trapezoid)
TEST(FigureTest, CenterCalculation) {
    Trapezoid trap;
    // Для установки точек используем отдельные операции ввода
    std::stringstream ss;
    ss << "0 0 4 0 4 4 0 4";
    ss >> trap;
    
    Point center = trap.center();
    EXPECT_NEAR(center.x, 2.0, 0.001);
    EXPECT_NEAR(center.y, 2.0, 0.001);
}

// Тесты для Trapezoid
TEST(TrapezoidTest, AreaCalculation) {
    Trapezoid trap;
    std::stringstream ss;
    ss << "0 0 4 0 3 2 1 2";
    ss >> trap;
    
    double area = trap.area();
    EXPECT_GT(area, 0.0);
}

TEST(TrapezoidTest, EqualityOperator) {
    Trapezoid trap1, trap2;
    std::stringstream ss1, ss2;
    ss1 << "0 0 4 0 3 2 1 2";
    ss2 << "0 0 4 0 3 2 1 2";
    
    ss1 >> trap1;
    ss2 >> trap2;
    
    EXPECT_TRUE(trap1 == trap2);
}

// Тесты для Rhombus
TEST(RhombusTest, AreaCalculation) {
    Rhombus rhomb;
    std::stringstream ss;
    ss << "0 0 2 3 4 0 2 -3";
    ss >> rhomb;
    
    double area = rhomb.area();
    EXPECT_GT(area, 0.0);
}

// Тесты для Pentagon
TEST(PentagonTest, AreaCalculation) {
    Pentagon pent;
    std::stringstream ss;
    ss << "0 0 1 2 3 3 4 1 2 -1";
    ss >> pent;
    
    double area = pent.area();
    EXPECT_GT(area, 0.0);
}

// Тесты для Array
TEST(ArrayTest, AddAndRemoveFigures) {
    Array array(3);
    
    EXPECT_EQ(array.getSize(), 0);
    EXPECT_EQ(array.getCapacity(), 3);
    
    Trapezoid* trap = new Trapezoid();
    std::stringstream ss1;
    ss1 << "0 0 4 0 3 2 1 2";
    ss1 >> *trap;
    array.addFigure(trap);
    
    EXPECT_EQ(array.getSize(), 1);
    
    Rhombus* rhomb = new Rhombus();
    std::stringstream ss2;
    ss2 << "0 0 2 3 4 0 2 -3";
    ss2 >> *rhomb;
    array.addFigure(rhomb);
    
    EXPECT_EQ(array.getSize(), 2);
    
    array.remove(0);
    EXPECT_EQ(array.getSize(), 1);
}

TEST(ArrayTest, TotalAreaCalculation) {
    Array array(2);
    
    Trapezoid* trap = new Trapezoid();
    std::stringstream ss1;
    ss1 << "0 0 4 0 3 2 1 2";
    ss1 >> *trap;
    array.addFigure(trap);
    
    Rhombus* rhomb = new Rhombus();
    std::stringstream ss2;
    ss2 << "0 0 2 3 4 0 2 -3";
    ss2 >> *rhomb;
    array.addFigure(rhomb);
    
    double totalArea = array.totalArea();
    EXPECT_GT(totalArea, 0.0);
}

TEST(ArrayTest, OverflowHandling) {
    Array array(1);
    
    Trapezoid* trap = new Trapezoid();
    std::stringstream ss;
    ss << "0 0 4 0 3 2 1 2";
    ss >> *trap;
    array.addFigure(trap);
    
    Rhombus* rhomb = new Rhombus();
    EXPECT_THROW(array.addFigure(rhomb), std::overflow_error);
    delete rhomb;
}

TEST(ArrayTest, OutOfBoundsHandling) {
    Array array(2);
    
    Trapezoid* trap = new Trapezoid();
    std::stringstream ss;
    ss << "0 0 4 0 3 2 1 2";
    ss >> *trap;
    array.addFigure(trap);
    
    EXPECT_THROW(array.remove(5), std::out_of_range);
}

// Тест оператора приведения к double
TEST(FigureTest, DoubleConversion) {
    Trapezoid trap;
    std::stringstream ss;
    ss << "0 0 4 0 3 2 1 2";
    ss >> trap;
    
    double area1 = trap.area();
    double area2 = static_cast<double>(trap);
    
    EXPECT_DOUBLE_EQ(area1, area2);
}

// Тест вывода фигур с красивым форматом точек
TEST(FigureTest, PrintOutput) {
    Trapezoid trap;
    std::stringstream in_ss;
    in_ss << "0 0 4 0 3 2 1 2";
    in_ss >> trap;
    
    std::stringstream out_ss;
    out_ss << trap;
    
    std::string output = out_ss.str();
    EXPECT_FALSE(output.empty());
    
    // Проверяем что вывод содержит скобки (красивый формат)
    EXPECT_NE(output.find("("), std::string::npos);
    EXPECT_NE(output.find(")"), std::string::npos);
    EXPECT_NE(output.find(","), std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}