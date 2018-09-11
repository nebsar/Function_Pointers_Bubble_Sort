/* 
 * File:   main.cpp
 * Author: Eagleye
 *
 * Created on September 9, 2018, 12:18 PM
 */

#include <cstdlib>
#include <random>
#include <ctime>
#include <iostream>

using namespace std;

#define ARRAYLEN(arr) ((sizeof(arr))/(sizeof(int)))

/**
 * @brief creates an array of integer with 100 elements and assigns random numbers to elements of the array.
 *        Applies bubble sort to array with a functor compare as a predicate.
 */
struct Compare {

    bool operator()(int first, int second) const {
        if (first < second)
            return true;
        else return false;

    }

    bool m_bigger = false;
};

bool compareFunct(int first, int second) {
    if (first < second)
        return true;
    else return false;
}

template<typename T>
void BubbleSort(int lenght, int* array, T pred) {
    for (unsigned short int i = 0; i < lenght; i++) {
        for (unsigned short int j = 0; j < lenght - 1; j++) {
            if (!pred(array[j], array[j + 1])) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char** argv) {

    srand(time(0));

    int array[100] = {};

    for (unsigned short int i = 0; i < 100; i++) {
        array[i] = (rand() % 101);
    }

    int length = ARRAYLEN(array);

    bool (*compf) (int, int) = compareFunct; //function pointer

    BubbleSort(length, array, compf);

    for (int i = 0; i < ARRAYLEN(array); i++) {
        cout << array[i] << endl;
    }

    BubbleSort(length, array, Compare());

    for (int i = 0; i < ARRAYLEN(array); i++) {
        cout << array[i] << endl;
    }

    BubbleSort(length, array, [](int first, int second) -> const bool {
        if (first > second)
            return true;
        else return false;
    });

    for (int i = 0; i < ARRAYLEN(array); i++) {
        cout << array[i] << endl;
    }

    return 0;
}





