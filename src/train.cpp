// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

void Train::addCar(bool light) {
    Car* newCar = new Car;
    newCar->light = light;
    if (!first) {
        newCar->next = newCar;
        newCar->prev = newCar;
        first = newCar;
    } else {
        Car* last = first->prev;
        newCar->next = first;
        newCar->prev = last;
        last->next = newCar;
        first->prev = newCar;
    }
}

int Train::getLength() {
    if (!first) return 0;
    
    countOp = 0;
    Car* current = first;
    
    if (!current->light) {
        current->light = true;
        countOp++;
    }

    while (true) {
        int steps = 0;
        while (true) {
            current = current->next;
            steps++;
            countOp++;
            if (current->light || current == first) break;
        }

        if (current == first && !current->light) {
            break;
        }

        if (current->light) {
            current->light = false;
            countOp++;
        }

        for (int i = 0; i < steps; i++) {
            current = current->prev;
            countOp++;
        }

        if (!current->light) {
            return steps;
        }
    }
    return 0;
}

int Train::getOpCount() {
    return countOp;
}
