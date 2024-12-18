// шаблоны функций.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <chrono>
#include <thread>
#include <random>
#include <ctime>
#include <iomanip>

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

    
    t max() {
        t Max = arr[0];
        for (int i{}; i < size; ++i) {
            if (Max < arr[i])
                Max = arr[i];
        }
        std::cout << std::endl;
        std::cout << "Максимальное число " << Max << std::endl;
        return Max;
    }

    
    t min() {
        t Min = arr[0];
        for (int i{}; i < size; ++i) {
            if (Min > arr[i])
                Min = arr[i];
        }
        std::cout << std::endl;
        std::cout << "Минимальное число " << Min << std::endl;
        return Min;
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


    
    unsigned int binarySearch(t target) {
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



//Создайте шаблонный класс матрица. Необходимо реали
//зовать динамическое выделение памяти, очистку памяти,
//заполнение матрицы с клавиатуры, заполнение случайны
//ми значениями, отображение матрицы, арифметические
//операции с помощью перегруженных операторов(+, –, и т.д)
//поиск макс и мин

template <typename T>
class Matrix {
    size_t rows;
    size_t cols;
    T** arr;

public:
    Matrix(size_t _rows, size_t _cols) : rows(_rows), cols(_cols), arr(nullptr) {
        if (_rows > 0 && _cols > 0) {
            arr = new T * [_rows];
            for (size_t i{}; i < _rows; ++i) {
                arr[i] = new T[_cols];
            }
        }
        std::cout << std::endl;
        std::cout << "Создана матрица с " << rows  << " количеством строк и " << cols << " количеством столбцов" << std::endl;
        std::cout << std::endl;
    }

    ~Matrix(){
       
         delete[] arr;
        
    
    }


    void AddArray() {
        std::cout << "Введите кол-во строк" << std::endl;
        std::cin >> rows;
        std::cout << "Введите кол-во столбцов" << std::endl;
        std::cin >> cols;
        
        if (rows > 0 && cols > 0) {
            if (arr != nullptr) {
                for (size_t i{}; i < rows; ++i) {
                    delete[] arr[i];
                    delete[] arr;
                }
            }
            arr = new T*[rows+1];
            for (size_t i = 0; i < rows; ++i) {
                arr[i] = new T[cols+1];
                for (size_t j = 0; j < cols; ++j) {
                    std::cout << "Введите элемент матрицы [" << i + 1 << "][" << j + 1 << "]: ";
                    std::cin >> arr[i][j];
                }
            }
        }
        else {
            std::cout << "Размер массива должен быть больше 0" << std::endl;
        }
    }

    void GenArray() {
        for (int i{}; i < rows; ++i) {
            for (int j{}; j < cols; ++j) {
                arr[i][j] = rand() % 11;
            }
            
        }
    }
   
    Matrix operator +(const Matrix& other)const {
        Matrix <T> result(rows, cols);
        for (size_t i{}; i < rows; ++i) {
            for (size_t j{}; j < cols; ++j) {
                result.arr[i][j] = arr[i][j] + other.arr[i][j];
            }
        }
        return result;
    }

    Matrix operator -(const Matrix& other)const {
        Matrix <T> result(rows, cols);
        for (size_t i{}; i < rows; ++i) {
            for (size_t j{}; j < cols; ++j) {
                result.arr[i][j] = arr[i][j] - other.arr[i][j];
            }
        }
        return result;
    }
    
    Matrix operator /(const Matrix& other)const {
        Matrix <T> result(rows, cols);
        for (size_t i{}; i < rows; ++i) {
            for (size_t j{}; j < cols; ++j) {
                result.arr[i][j] = arr[i][j] / other.arr[i][j];
            }
        }
        return result;
    }

    Matrix operator *(const Matrix& other) const {
        Matrix <T> result(rows, cols);
        for (size_t i{}; i < rows; ++i) {
            for (size_t j{}; j < cols; ++j) {
                result.arr[i][j] = arr[i][j] * other.arr[i][j];
            }
        }
        return result;
    }

    T max() {
        T max = arr[0][0];
        for (size_t i{}; i < rows; ++i) {
            for (size_t j{}; j < cols; ++j) {
                if (max < arr[i][j]) {
                    max = arr[i][j];
                }
            }
        }
        std::cout << std::endl;
        std::cout << "Максимальное число " << max << std::endl;
        return max;
    }

    T min() {
        T min = arr[0][0];
        for (size_t i{}; i < rows; ++i) {
            for (size_t j{}; j < cols; ++j) {
                if (min > arr[i][j]) {
                    min = arr[i][j];
                }
            }
        }
        std::cout << std::endl;
        std::cout << "Минимальное число " << min << std::endl;
        return min;
    }

    void Print() {
        for (int i{}; i < rows; ++i) {
            for (int j{}; j < cols; ++j) {
                std::cout << arr[i][j] << " ";
                
            }
        }
            
    }
};


//Есть строка символов, признаком конца, которой являетcя;
//В строке могут быть фигурные, круглые, квадратные
//скобки.Скобки могут быть открывающими и закрыва
//ющими.
//Необходимо проверитькорректность расстановки скобок.
//При этом необходимо, чтобы выполнились следующие
//правила :
//1. Каждая открывающая скобка должна иметь справа
//такуюжезакрывающую.Обратноетакжедолжнобыть
//верно.
//2. Открывающие и закрывающие пары скобок разных
//типов должны быть правильно расположены по от
//ношению друг к другу.
//■ Пример правильной строки : ({ x - y - z }*[x + 2y] - (z + 4x));
//■ Пример неправильной строки : ([x - y - z}*[x + 2y) - {z + 4x)].
//Если все правила соблюдены выведите информационное
//сообщение о корректности строки, иначе покажите строку
//до места возникновения первой ошибки



bool checkParentheses(const std::string& str) {
    std::stack<char> s;
    for (char c : str) {
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (s.empty()) {
                return false; 
            }
            char top = s.top();
            s.pop();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false; 
                
            }
        }
    }

    return s.empty(); 
}

 /*Разработать приложение, имитирующее очередь печати 
принтера. Должныбытьклиенты,посылающиезапросы 
на принтер, у каждого из которых есть свой приоритет. 
Каждыйновыйклиентпопадаетвочередьвзависимости 
от своего приоритета. Необходимо сохранять статисти
ку печати (пользователь, время) в отдельной очереди. 
Предусмотреть вывод статистики на экран*/


struct PrintJob {
    int clientId;
    int priority; 
    std::chrono::system_clock::time_point submissionTime;
    std::chrono::system_clock::time_point completionTime;

    PrintJob(int id, int p) : clientId(id), priority(p), submissionTime(std::chrono::system_clock::now()) {}
};


struct ComparePrintJobs {
    bool operator()(const PrintJob& a, const PrintJob& b) const {
        if (a.priority != b.priority) {
            return a.priority < b.priority;
        }
        return a.submissionTime > b.submissionTime; 
    }
};

int main()
{
    srand(time(NULL));

    setlocale(LC_ALL, "ru");




    /*MyArray <int> a{ 10 };
    a.gen();
    a.print();
    a.max();
    a.min();*/
    /*a.sort();
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
    a.print();*/











    /*Matrix <int> m(3,3);
    m.AddArray();
    m.GenArray();
    m.Print();*/
    /*Matrix <int> m1(3, 3);
    m1.GenArray();
    std::cout << "Матрица 1" << std::endl;
    m1.Print();
    Matrix <int> m2(3, 3);
    m2.GenArray();
    std::cout << "Матрица 2" << std::endl;
    m2.Print();
    Matrix <int> m3(m1 + m2);
    m3.Print();*/

    /*Matrix <int> m4(3, 3);
    m4.GenArray();
    std::cout << "Матрица 1" << std::endl;
    m4.Print();
    Matrix <int> m5(3, 3);
    m5.GenArray();
    std::cout << "Матрица 2" << std::endl;
    m5.Print();
    Matrix <int> m6(m4 + m5);
    m6.Print();*/

    /*Matrix <int> m7(3, 3);
    m7.GenArray();
    std::cout << "Матрица 1" << std::endl;
    m7.Print();
    Matrix <int> m8(3, 3);
    m8.GenArray();
    std::cout << "Матрица 2" << std::endl;
    m8.Print();
    Matrix <int> m9(m7 / m8);
    m9.Print();*/

    /*Matrix <int> m10(3, 3);
    m10.GenArray();
    std::cout << "Матрица 1" << std::endl;
    m10.Print();
    Matrix <int> m11(3, 3);
    m11.GenArray();
    std::cout << "Матрица 2" << std::endl;
    m11.Print();
    Matrix <int> m12(m10 * m11);
    m12.Print();*/



   /* Matrix <int> m13(3, 3);
    m13.GenArray();
    m13.Print();
    Matrix <int> m14(3, 3);
    m14.GenArray();
    m14.Print();
    m13.max();
    m13.min();
    m14.max();
    m14.min();*/

//std::string str1 = "((()))";
//std::string str2 = "([{}])";
//std::string str3 = "({)}";
//std::string str4 = "(()";
//
//std::cout << "\"" << str1 << "\" - balanced: " << checkParentheses(str1) << std::endl; // true
//std::cout << "\"" << str2 << "\" - balanced: " << checkParentheses(str2) << std::endl; // true
//std::cout << "\"" << str3 << "\" - balanced: " << checkParentheses(str3) << std::endl; // false
//std::cout << "\"" << str4 << "\" - balanced: " << checkParentheses(str4) << std::endl; // false

std::priority_queue<PrintJob, std::vector<PrintJob>, ComparePrintJobs> printQueue;
std::vector<PrintJob> printHistory;
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> clientIdDist(1, 100); 
std::uniform_int_distribution<> priorityDist(0, 2);    

// Имитация поступления задач на печать
for (int i = 0; i < 10; ++i) {
    int clientId = clientIdDist(gen);
    int priority = priorityDist(gen);
    PrintJob job(clientId, priority);
    printQueue.push(job);
    std::cout << "Задача от клиента " << clientId << " (приоритет " << priority << ") добавлена в очередь.\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); 
}


// Имитация процесса печати
while (!printQueue.empty()) {
    PrintJob currentJob = printQueue.top();
    printQueue.pop();

    // Имитация времени печати
    std::this_thread::sleep_for(std::chrono::milliseconds(500 + (2 - currentJob.priority) * 200));

    currentJob.completionTime = std::chrono::system_clock::now();
    printHistory.push_back(currentJob);
    std::cout << "Задача от клиента " << currentJob.clientId << " (приоритет " << currentJob.priority << ") завершена.\n";
}


 std::cout << "\nСтатистика печати:\n";
    for (const auto& job : printHistory) {
        auto submissionTime = job.submissionTime;
        auto completionTime = job.completionTime;
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(completionTime - submissionTime);
        std::time_t submission_time_c = std::chrono::system_clock::to_time_t(submissionTime);
        std::time_t completion_time_c = std::chrono::system_clock::to_time_t(completionTime);

        char submissionTimeBuffer[80]; 
        char completionTimeBuffer[80]; 
        ctime_s(submissionTimeBuffer, sizeof(submissionTimeBuffer), &submission_time_c);
        ctime_s(completionTimeBuffer, sizeof(completionTimeBuffer), &completion_time_c);


        std::cout << "Клиент: " << job.clientId << ", Приоритет: " << job.priority
                  << ", Время отправки: " << submissionTimeBuffer
                  << ", Время завершения: " << completionTimeBuffer
                  << ", Время печати: " << duration.count() << " мс\n";
    }

    return 0;

}
