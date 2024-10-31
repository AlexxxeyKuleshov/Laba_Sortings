#include <iostream>
#include "strings.cpp"
#include <windows.h>


int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    std::cout << "Выберите метод обработки строки: " << std::endl;
    std::cout << "1 - Строка как массив символов" << std::endl;
    std::cout << "2 - Строка в стиле C" << std::endl;
    std::cout << "3 - Строка из файла" << std::endl;

    int choice;
    std::cin >> choice;
    std::cin.ignore();

    if (choice == 1) {
        char str[100];
        std::cout << "Введите строку: ";
        std::cin.getline(str, 100);
        std::cout << "Результат: " << std::endl;
        processArray(str);
    } 
    else if (choice == 2) {
        char str[100];
        std::cout << "Введите строку: ";
        std::cin.getline(str, 100);
        std::cout << "Результат: " << std::endl;
        processCString(str);
    } 
    else if (choice == 3) {
        processFile("text.txt", "output.txt");
        std::cout << "Обработанная строка записана в файл output.txt" << std::endl;
    } 
    else {
        std::cout << "Неверный выбор." << std::endl;
    }

    return 0;
}
