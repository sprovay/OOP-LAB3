#include <iostream>
#include "array.h"
#include "trapezoid.h"
#include "rhombus.h"
#include "pentagon.h"

int main() {
    Array array(5);
    
    Trapezoid* trap = new Trapezoid();
    std::cout << "Введите 4 точки трапеции: "; // 0 0 4 0 3 2 1 2
    std::cin >> *trap;
    array.addFigure(trap);

    Rhombus* rhomb = new Rhombus();
    std::cout << "Введите 4 точки ромба: "; // 0 0 2 3 4 0 2 -3
    std::cin >> *rhomb;
    array.addFigure(rhomb);

    Pentagon* pent = new Pentagon();
    std::cout << "Введите 5 точек пятиугольника: "; // 0 0 2 1 4 0 3 -2 1 -2
    std::cin >> *pent;
    array.addFigure(pent);
    
    array.printAll();
    std::cout << "Общая площадь: " << array.totalArea() << std::endl;
    
    array.remove(1);

    array.printAll();
    std::cout << "Общая площадь после удаления: " << array.totalArea() << std::endl;

    return 0;
}