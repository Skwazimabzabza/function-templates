// шаблоны функций.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

/*Реализуйте шаблонные функции для поиска максимума,
минимума, сортировки массива (любым алгоритмом сортировки), двоичного поиска в массиве, замены элемента
массива на переданное значение.*/



/* Нахождение минимума сделал криво */

template <typename t>
class MyArray {

    t size{};
    t* arr{};

public:

    MyArray(t  s) : size{ s }, arr{ new t[size] {} } {
        std::cout << "Create aray  size =  " << size << std::endl;
    }

    ~MyArray() {
        delete[] arr;
    }

    void print() {
        for (int i{}; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
    }

    void gen() {
        for (int i{}; i < size; ++i) {
            arr[i] = rand() % 101;
        }
    }

    template <typename t>
    t max(t max) {
        for (int i{}; i < size; ++i) {
            if (arr[i] > max)
                max = arr[i];
        }
        std::cout << std::endl;
        std::cout << "Максимальное число " << max << std::endl;
        return max;
    }

    template <typename t>
    t min(t min) {
        for (int i{}; i < size; ++i) {
            if (min > arr[i])
                min = arr[i];
        }
        std::cout << std::endl;
        std::cout << "Минимальное число " << min << std::endl;
        return min;
    }

    void sort() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
        std::cout << "Массив отсортирован" << std::endl;
    }


    template <typename t>
    t binarySearch(t target) {
        int left = 0;
        int right = size - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return mid;
            }
            else if (arr[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return -1;

    }

    template <typename t>
    void replaceElement(t index, t newValue) {
        if (index >= 0 && index < size) {
            arr[index] = newValue;
        }
        else {
            std::cout << "Ошибка: индекс вне диапазона массива" << std::endl;
        }
    }
};

int main()
{
    srand(time(NULL));

    setlocale(LC_ALL, "ru");

    


    MyArray <int> a{ 10 };
    a.gen();
    a.print();
    a.max(0);
    a.min(100000);
    a.sort();
    a.print();

    int target = 1;
    int result = a.binarySearch(target);

    if (result != -1) {
        std::cout << "Элемент найден на индексе: " << result << std::endl;
    }
    else {
        std::cout << std::endl;
        std::cout << "Элемент " << target << " не найден" << std::endl;
        std::cout << std::endl;
    }

    std::cout << "Замена элемента" << std::endl;
    int size;
    int index = 2;
    int newValue = 10;
    a.replaceElement(index, newValue);
    a.print();
}
