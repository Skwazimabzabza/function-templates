// шаблоны функций.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

/*Реализуйте шаблонные функции для поиска максимума,
минимума, сортировки массива (любым алгоритмом сортировки), двоичного поиска в массиве, замены элемента
массива на переданное значение.*/



/*Нахождение минимума сделал криво*/


class MyArray {

    unsigned int size{};
    int* arr{};

public:

    MyArray(unsigned int  s) : size{ s }, arr{ new int[size] {} } {
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

    template <typename t>
    t sort(t temp) {
        for (int i{}; i < size - 1; i++) {
            for (int j{}; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    
                }
            }
            return temp;
        }
        std::cout << std::endl;
        std::cout << "Сортировка массива" << std::endl;
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

    int temp{};
    

    MyArray a{ 10 };
    a.gen();
    a.print();
    a.max(0);
    a.min(100000);
    a.sort(temp);
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
