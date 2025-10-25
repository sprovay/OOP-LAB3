#ifndef PENTAGON_H
#define PENTAGON_H

#include "figure.h"

class Pentagon : public Figure {
public:
    Pentagon() : Figure(5) {};

    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
};

#endif