#ifndef ARRAY_H
#define ARRAY_H

#include "figure.h"
#include "trapezoid.h"
#include "rhombus.h"
#include "pentagon.h"

class Array {
public:
    Array(unsigned int arraySize = 20);
    ~Array();

    double totalArea() const;
    void printAll() const;

    void addFigure(Figure* fig);
    void remove(unsigned int index);

    unsigned int getSize() const;
    unsigned int getCapacity() const;

private:
    unsigned int figureCount;
    unsigned int capacity;
    Figure** figures;
};

#endif