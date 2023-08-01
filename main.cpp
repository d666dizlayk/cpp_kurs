#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "array.h" // Включение заголовочного файла с функциями для работы с массивами
#include "binary_sort.h" // Включение заголовочного файла с функцией сортировки

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian"); // русский язык в консоли
    int size;
    int max_value;
    int* array;

    cout << "Введите размер массива (не более 40 и не менее 1): ";
    size = vvod(1, 40); // Ввод размера массива с помощью vvod из файла array.h

    array = new int[size]; // Выделение памяти под массив размером size

    cout << "Выберите способ заполнения массива (введите число):\n";
    cout << "1. С помощью датчика случайных чисел\n";
    cout << "2. Из файла\n";
    cout << "3. С клавиатуры\n";
    int choice = vvod(1, 3); // Ввод выбора пользователя с помощью функции vvod из файла array.h

    switch (choice) {
    case 1: {
        cout << "Введите максимальное значение элементов массива (не более 99 и не менее 0): ";
        max_value = vvod(0, 99); // Ввод максимального значения элементов с помощью функции vvod из файла array.h
        RandomArray(array, size, max_value); // Заполнение массива случайными числами с помощью функции RandomArray из файла array.h
        break;
    }
    case 2: {
        cout << "Убедитесь, что файл с числами находится в папке.\n";
        FileArray(array, size); // Заполнение массива из файла с помощью функции FileArray из файла array.h
        break;
    }
    case 3: {
        KeyboardArray(array, size); // Заполнение массива с клавиатуры с помощью функции KeyboardArray из файла array.h
        break;
    }

    }

    if (array == nullptr) {
        cout << "Ошибка выделения памяти.\n"; // В случае ошибки вывод сообщения и завершение программы
        return 0;
    }

    cout << "Исходный массив: ";
    printArray(array, size); // Вывод исходного массива на экран с помощью printArray из файла binary_sort.h

    int comparisons = 0; // Переменная для подсчета числа сравнений
    int swaps = 0; // Переменная для подсчета числа перестановок
    BinarySort(array, size, comparisons, swaps); // Сортировка массива методом бинарной вставки с помощью BinarySort из файла binary_sort.h

    cout << "Отсортированный массив: ";
    printArray(array, size); // Вывод отсортированного массива на экран

    cout << "Число сравнений: " << comparisons << endl; // Вывод числа сравнений на экран
    cout << "Число перестановок: " << swaps << endl; // Вывод числа перестановок на экран

    delete[] array; // Освобождение памяти, выделенной для массива



    system("pause"); // чтобы не закрывалась консоль в .exe приложении
}
