#include "array.h"
#include <iostream>

Array::Array(unsigned int arraySize) 
    : figureCount(0), capacity(arraySize) {
    
    figures = new Figure*[capacity];
    for (unsigned int i = 0; i < capacity; ++i) {
        figures[i] = nullptr;
    }
}

Array::~Array() {
    for (unsigned int i = 0; i < figureCount; ++i) {
        delete figures[i];
    }
    delete[] figures;
}

double Array::totalArea() const {
    double total = 0;
    for (unsigned int i = 0; i < figureCount; ++i) {
        total += figures[i]->area();
    }
    return total;
}

void Array::printAll() const {
    std::cout << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "===========ФИГУРЫ В МАССИВЕ==============" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    for (unsigned int i = 0; i < figureCount; i++) {
        std::cout << "Фигура " << i << ": " << *figures[i] << std::endl;
        
        Point center = figures[i]->center();
        std::cout << "  - Центр: (" << center.x << ", " << center.y << ")" << std::endl;
        
        double area = figures[i]->area();
        std::cout << "  - Площадь: " << area << std::endl;
        
        std::cout << "=========================================" << std::endl;
    }
    std::cout << std::endl;
}

void Array::addFigure(Figure* fig) {
    if (figureCount < capacity) {
        figures[figureCount++] = fig;
    } else {
        throw std::overflow_error("Массив фигур переполнен!");
    }
}

void Array::remove(unsigned int index) {
    if (index >= figureCount) {
        throw std::out_of_range("Индекс выходит за границы массива фигур!");
    }
    
    delete figures[index];
    for (unsigned int i = index; i < figureCount - 1; ++i) {
        figures[i] = figures[i + 1];
    }
    figures[figureCount - 1] = nullptr;
    figureCount--;
}

unsigned int Array::getSize() const {
    return figureCount;
}

unsigned int Array::getCapacity() const {
    return capacity;
}