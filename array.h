#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int vvod(int min, int max) {
    // ������� ����������� � ������������ ����� ����� � �������� ���������
    int value;
    while (true) {
        cin >> value;

        if (cin.fail()) {
            // ���� ��������� ������ ��� ����� (��������, ������� �� �����), ���������� ���� ������ � ������� ����� �����
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������������ ����. ���������� ��� ���: ";
        }
        else if (value < min || value > max) {
            // ���� ��������� �������� �� �������� � �������� ��������, ������� ��������� �� ������
            cout << "�������� ������ ���� �� " << min << " �� " << max << ". ���������� ��� ���: ";
        }
        else {
            // ��������� �������� ���������, ������� �� �����
            break;
        }
    }

    return value;
}

void RandomArray(int* array, int size, int max_value) {
    // ������� ��������� ������ ���������� ������� � ��������� �� 0 �� max_value
    srand(static_cast<unsigned int>(time(0))); // �������������� ��������� ��������� �����
    for (int i = 0; i < size; i++) {
        array[i] = rand() % (max_value + 1); // ���������� ��������� ����� �� 0 �� max_value � ��������� � �������
    }
}

void FileArray(int* array, int& size) {
    int fileCount = 0; // ������� ������
    int index = 0; // ������ ��� �������, ����� ���������� ������������� �����

    while (true) {
        std::string filename;
        std::cout << "������� �������� ����� (� �����������): ";
        std::cin >> filename;

        std::ifstream file(filename); // ��������� ���� ��� ������

        if (!file) {
            std::cout << "������ �������� �����. ������� ���������� ��������.\n";
            continue;
        }

        bool success = true;
        int num; // ���������� ��� ������ ����� �� �����

        while ((file >> num)) {
            if (num < 0) {
                std::cout << "����� " << num << " ������ ����. ������� �����.\n";
                continue; // ���������� ������������� ����� � ��������� � ��������� �������� �����
            }

            array[index] = num;
            index++;

            if (index == size) {
                break; // ���������� ���������� ������� ��� ���������� ���������� �������� �������
            }
        }

        fileCount += index;
        file.close(); // ��������� ����

        if (index == 0) {
            std::cout << "���� �� �������� �����. ���������� ������ �����.\n";
            break;
        }

        if (success) {
            break;
        }
    }

    if (fileCount < size) {
        std::cout << "���������� ��������� � ����� ������ ������� �������. ����������� �������� ����� ���������������.\n";
        size = fileCount; // ������������� ������ ������� ������ ���������� ��������� � �����
    }

    //std::string outputFilename;
    //std::cout << "������� �������� ����� ��� ������ ������� (� �����������): ";
    //std::cin >> outputFilename;

    //std::ofstream outputFile(outputFilename); // ��������� ���� ��� ������

    //if (outputFile) {
    //    for (int i = 0; i < index; i++) {
    //        outputFile << array[i] << " "; // ���������� �������� ������� � ���� ����� ������
    //    }
    //    outputFile.close(); // ��������� ����
    //}
}







void KeyboardArray(int* array, int size) {
    // ������� ����������� � ������������ �������� ������� � ����������
    cout << "������� �������� �������:\n";
    for (int i = 0; i < size; i++) {
        cout << "������� " << i + 1 << ": ";
        array[i] = vvod(0, numeric_limits<int>::max()); // ����������� � ������������ ����� �����
    }
}
