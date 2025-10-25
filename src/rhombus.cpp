#include "rhombus.h"
#include <iostream>

void Rhombus::print(std::ostream& os) const {
    os << "Ромб: ";
    for (unsigned int i = 0; i < amountOfPoints; ++i) {
        os << points[i];
        if (i < amountOfPoints - 1) os << " ";
    }
}

void Rhombus::read(std::istream& is) {
    for (unsigned int i = 0; i < amountOfPoints; ++i) {
        is >> points[i];
    }
}