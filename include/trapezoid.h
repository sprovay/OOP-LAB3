#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "figure.h"

class Trapezoid : public Figure {
public:
    Trapezoid() : Figure(4) {}
    
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
};

#endif