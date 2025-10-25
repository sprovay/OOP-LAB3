#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figure.h"

class Rhombus : public Figure {
public:
    Rhombus() : Figure(4) {}

    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
};

#endif