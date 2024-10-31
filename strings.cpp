#include "strings.h"
#include <cstring>
#include <fstream>
#include <iostream>

void processArray(char str[]) {
    int firstColon = -1, lastColon = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ':') {
            if (firstColon == -1) {
                firstColon = i;
            }
            lastColon = i;
        }
    }

    if (firstColon == lastColon && firstColon != -1) {
        char subStr[100];
        int j = 0;

        for (int i = firstColon + 1; str[i] != '\0'; i++) {
            subStr[j++] = str[i];
        }
        subStr[j] = '\0';

        int len = 0;
        while (subStr[len] != '\0') {
            len++;
        }

        if (len > 1) {
            char temp = subStr[0];
            subStr[0] = subStr[len - 1];
            subStr[len - 1] = temp;
        }

        std::cout << subStr << std::endl;
    }
    else if (firstColon != -1 && lastColon != -1) {
        for (int i = firstColon + 1; i < lastColon; i++) {
            std::cout << str[i];
        }
        std::cout << std::endl;
    }
}

void processCString(char* str) {
    char* firstColon = nullptr;
    char* lastColon = nullptr;

    for (char* ptr = str; *ptr != '\0'; ptr++) {
        if (*ptr == ':') {
            if (firstColon == nullptr) {
                firstColon = ptr;
            }
            lastColon = ptr;
        }
    }

    if (firstColon == lastColon && firstColon != nullptr) {
        char subStr[100];
        int j = 0;

        for (char* ptr = firstColon + 1; *ptr != '\0'; ptr++) {
            subStr[j++] = *ptr;
        }
        subStr[j] = '\0';

        int len = 0;
        while (subStr[len] != '\0') {
            len++;
        }

        if (len > 1) {
            char temp = subStr[0];
            subStr[0] = subStr[len - 1];
            subStr[len - 1] = temp;
        }

        std::cout << subStr << std::endl;
    }
    else if (firstColon != nullptr && lastColon != nullptr) {
        for (char* ptr = firstColon + 1; ptr != lastColon; ptr++) {
            std::cout << *ptr;
        }
        std::cout << std::endl;
    }
}

void processFile(const char* inputFilename, const char* outputFilename) {
    std::ifstream inputFile(inputFilename);
    if (!inputFile) {
        std::cerr << "Не удалось открыть файл для чтения." << std::endl;
        return;
    }

    std::ofstream outputFile(outputFilename);
    if (!outputFile) {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;
        return;
    }

    char str[100];
    inputFile.getline(str, 100);

    int firstColon = -1, lastColon = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ':') {
            if (firstColon == -1) {
                firstColon = i;
            }
            lastColon = i;
        }
    }

    if (firstColon == lastColon && firstColon != -1) {
        char subStr[100];
        int j = 0;

        for (int i = firstColon + 1; str[i] != '\0'; i++) {
            subStr[j++] = str[i];
        }
        subStr[j] = '\0';

        int len = 0;
        while (subStr[len] != '\0') {
            len++;
        }

        if (len > 1) {
            char temp = subStr[0];
            subStr[0] = subStr[len - 1];
            subStr[len - 1] = temp;
        }

        outputFile << subStr << std::endl;
    }
    else if (firstColon != -1 && lastColon != -1) {
        for (int i = firstColon + 1; i < lastColon; i++) {
            outputFile << str[i];
        }
        outputFile << std::endl;
    }

    inputFile.close();
    outputFile.close();
}
