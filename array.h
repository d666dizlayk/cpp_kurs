#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int vvod(int min, int max) {
    // Функция запрашивает у пользователя целое число в заданном диапазоне
    int value;
    while (true) {
        cin >> value;

        if (cin.fail()) {
            // Если произошла ошибка при вводе (например, введено не число), сбрасываем флаг ошибки и очищаем буфер ввода
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Некорректный ввод. Попробуйте еще раз: ";
        }
        else if (value < min || value > max) {
            // Если введенное значение не попадает в заданный диапазон, выводим сообщение об ошибке
            cout << "Значение должно быть от " << min << " до " << max << ". Попробуйте еще раз: ";
        }
        else {
            // Введенное значение корректно, выходим из цикла
            break;
        }
    }

    return value;
}

void RandomArray(int* array, int size, int max_value) {
    // Функция заполняет массив случайными числами в диапазоне от 0 до max_value
    srand(static_cast<unsigned int>(time(0))); // Инициализируем генератор случайных чисел
    for (int i = 0; i < size; i++) {
        array[i] = rand() % (max_value + 1); // Генерируем случайное число от 0 до max_value и сохраняем в массиве
    }
}

void FileArray(int* array, int& size) {
    int fileCount = 0; // Счетчик файлов
    int index = 0; // Индекс для массива, чтобы пропустить отрицательные числа

    while (true) {
        std::string filename;
        std::cout << "Введите название файла (с расширением): ";
        std::cin >> filename;

        std::ifstream file(filename); // Открываем файл для чтения

        if (!file) {
            std::cout << "Ошибка открытия файла. Введите корректное название.\n";
            continue;
        }

        bool success = true;
        int num; // Переменная для чтения чисел из файла

        while ((file >> num)) {
            if (num < 0) {
                std::cout << "Число " << num << " меньше нуля. Пропуск числа.\n";
                continue; // Пропускаем отрицательное число и переходим к следующей итерации цикла
            }

            array[index] = num;
            index++;

            if (index == size) {
                break; // Прекращаем заполнение массива при достижении последнего элемента массива
            }
        }

        fileCount += index;
        file.close(); // Закрываем файл

        if (index == 0) {
            std::cout << "Файл не содержит чисел. Завершение чтения файла.\n";
            break;
        }

        if (success) {
            break;
        }
    }

    if (fileCount < size) {
        std::cout << "Количество элементов в файле меньше размера массива. Недостающие элементы будут проигнорированы.\n";
        size = fileCount; // Устанавливаем размер массива равным количеству элементов в файле
    }

    //std::string outputFilename;
    //std::cout << "Введите название файла для записи массива (с расширением): ";
    //std::cin >> outputFilename;

    //std::ofstream outputFile(outputFilename); // Открываем файл для записи

    //if (outputFile) {
    //    for (int i = 0; i < index; i++) {
    //        outputFile << array[i] << " "; // Записываем элементы массива в файл через пробел
    //    }
    //    outputFile.close(); // Закрываем файл
    //}
}







void KeyboardArray(int* array, int size) {
    // Функция запрашивает у пользователя элементы массива с клавиатуры
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < size; i++) {
        cout << "Элемент " << i + 1 << ": ";
        array[i] = vvod(0, numeric_limits<int>::max()); // Запрашиваем у пользователя целое число
    }
}
