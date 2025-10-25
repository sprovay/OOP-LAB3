#include "figure.h"
#include <cmath>

Figure::Figure(unsigned int pointsAmount) {
    amountOfPoints = pointsAmount;
    points = new Point[pointsAmount];
}

Figure::Figure(const Figure& other) 
    : amountOfPoints(other.amountOfPoints), 
        points(new Point[other.amountOfPoints]) {
    for (unsigned int i = 0; i < amountOfPoints; ++i) {
        points[i] = other.points[i];
    }
}

Figure::Figure(Figure&& other)
    : amountOfPoints(other.amountOfPoints), 
        points(other.points) {
    other.points = nullptr;
    other.amountOfPoints = 0;
}

Figure::~Figure() {
    delete[] points;
}

double Figure::area() const {
    double area = 0.0;
    
    for (unsigned int i = 0; i < amountOfPoints; ++i) {
        unsigned int j = (i + 1) % amountOfPoints;
        area += points[i].x * points[j].y - points[j].x * points[i].y;
    }
    
    return std::abs(area) / 2.0;
}

unsigned int Figure::getAmountOfPoints() const {
    return amountOfPoints;
}

Point* Figure::getPoints() const {
    return points;
}

Point Figure::center() const {
    double X = 0, Y = 0;
    for (unsigned int i = 0; i < amountOfPoints; ++i) {
        X += points[i].x;
        Y += points[i].y;
    }
    return Point(X / amountOfPoints, Y / amountOfPoints);
}

bool Figure::operator==(const Figure& otherFig) const {
    if (amountOfPoints != otherFig.amountOfPoints) {
        return false;
    }
    
    for (unsigned int i = 0; i < amountOfPoints; ++i) {
        if (!(points[i] == otherFig.points[i])) {
            return false;
        }
    }
    
    return true;
}

Figure& Figure::operator=(const Figure& otherFig) {
    if (this != &otherFig) {
        delete[] points;
        amountOfPoints = otherFig.amountOfPoints;
        points = new Point[amountOfPoints];
        for (unsigned int i = 0; i < amountOfPoints; ++i) {
            points[i] = otherFig.points[i];
        }
    }
    return *this;
}

Figure& Figure::operator=(Figure&& otherFig) {
    if (this != &otherFig) {
        delete[] points;
        amountOfPoints = otherFig.amountOfPoints;
        points = otherFig.points;
        otherFig.points = nullptr;
        otherFig.amountOfPoints = 0;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Figure& fig) {
    fig.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, Figure& fig) {
    fig.read(is);
    return is;
}