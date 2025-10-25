#include "pentagon.h"
#include <iostream>

void Pentagon::print(std::ostream& os) const {
    os << "Пятиугольник: ";
    for (unsigned int i = 0; i < amountOfPoints; ++i) {
        os << points[i];
        if (i < amountOfPoints - 1) os << " ";
    }
}

void Pentagon::read(std::istream& is) {
    for (unsigned int i = 0; i < amountOfPoints; ++i) {
        is >> points[i];
    }
}