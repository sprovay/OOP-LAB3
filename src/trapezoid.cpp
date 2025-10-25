#include "trapezoid.h"
#include <iostream>

void Trapezoid::print(std::ostream& os) const {
    os << "Трапеция: ";
    for (unsigned int i = 0; i < amountOfPoints; ++i) {
        os << points[i];
        if (i < amountOfPoints - 1) os << " ";
    }
}

void Trapezoid::read(std::istream& is) {
    for (unsigned int i = 0; i < amountOfPoints; ++i) {
        is >> points[i];
    }
}