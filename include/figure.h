#ifndef FIGURE_H
#define FIGURE_H

#include "point.h"
#include <iostream>

class Figure {
public:
    Figure(unsigned int pointsAmount);
    Figure(const Figure& other);
    Figure(Figure&& other);
    virtual ~Figure();

    double area() const;

    explicit operator double() const {
        return area();
    }

    unsigned int getAmountOfPoints() const;
    Point* getPoints() const;

    Point center() const;

    bool operator==(const Figure& otherFig) const;
    Figure& operator=(const Figure& otherFig);
    Figure& operator=(Figure&& otherFig);
    
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure& fig);
    friend std::istream& operator>>(std::istream& is, Figure& fig);

protected:
    unsigned int amountOfPoints = 0;
    Point* points = nullptr;
};

#endif