#include <clocale>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>


// 1.2. Сумма знаков
int sumLastNums(int x) {
    return std::abs(x % 10) + std::abs((x / 10) % 10);
}

// 1.4. Есть ли позитив
bool isPositive(int x) {
    return x > 0;
}

// 1.6. Большая буква
bool isUpperCase(char x) {
    return x >= 'A' && x <= 'Z';
}

// 1.8. Делитель
bool isDivisor(int a, int b) {
    return b != 0 && a % b == 0;
}

// 1.10. Многократный вызов
int lastNumSum(int a, int b) {
    return std::abs(a % 10) + std::abs(b % 10);
}


// 2.2. Безопасное деление
double safeDiv(int x, int y) {
    if (y == 0) {
        return 0.0;
    }
    return static_cast<double>(x) / y;
}

// 2.4. Строка сравнения
std::string makeDecision(int x, int y) {
    std::string sign = "==";
    if (x > y) {
        sign = ">";
    }
    else if (x < y) {
        sign = "<";
    }
    return std::to_string(x) + " " + sign + " " + std::to_string(y);
}

// 2.6. Тройная сумма
bool sum3(int x, int y, int z) {
    return x + y == z || x + z == y || y + z == x;
}

// 2.8. Возраст
std::string age(int x) {
    int abs_x = std::abs(x);
    int last_digit = abs_x % 10;
    int last_two_digits = abs_x % 100;
    if (last_two_digits >= 11 && last_two_digits <= 14) {
        return std::to_string(x) + " лет";
    }
    if (last_digit == 1) {
        return std::to_string(x) + " год";
    }
    if (last_digit >= 2 && last_digit <= 4) {
        return std::to_string(x) + " года";
    }
    return std::to_string(x) + " лет";
}

// 2.10. Вывод дней недели
void printDays(int x) {
    switch (x) {
    case 1:
        std::cout << "понедельник\n";
    case 2:
        std::cout << "вторник\n";
    case 3:
        std::cout << "среда\n";
    case 4:
        std::cout << "четверг\n";
    case 5:
        std::cout << "пятница\n";
    case 6:
        std::cout << "суббота\n";
    case 7:
        std::cout << "воскресенье\n";
        break;
    default:
        std::cout << "это не день недели\n";
        break;
    }
}


// 3.2. Числа наоборот
std::string reverseListNums(int x) {
    std::string result;
    for (int i = x; i >= 0; --i) {
        result += std::to_string(i);
        if (i > 0) {
            result += " ";
        }
    }
    return result;
}

// 3.4. Степень числа
int pow(int x, int y) {
    int result = 1;
    for (int i = 0; i < y; ++i) {
        result *= x;
    }
    return result;
}

// 3.6. Одинаковость
bool equalNum(int x) {
    int last_digit = std::abs(x % 10);
    while (x != 0) {
        if (std::abs(x % 10) != last_digit) {
            return false;
        }
        x /= 10;
    }
    return true;
}

// 3.8. Левый треугольник
void leftTriangle(int x) {
    for (int i = 1; i <= x; ++i) {
        std::cout << std::string(i, '*') << "\n";
    }
}

// 3.10. Угадайка
void guessGame() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int secret = std::rand() % 10;
    int attempts = 0;
    std::string input;

    std::cout << "Введите число от 0 до 9:\n";
    while (true) {
        if (!(std::cin >> input)) {
            return;  // Ввод закончился, выходим из игры.
        }
        std::cin.ignore(10000, '\n');  // Остаток строки не нужен.
        if (input.size() != 1 || input[0] < '0' || input[0] > '9') {
            std::cout << "Нужно ввести одну цифру от 0 до 9:\n";
            continue;
        }
        ++attempts;
        if (input[0] - '0' == secret) {
            break;
        }
        std::cout << "Вы не угадали, введите число от 0 до 9:\n";
    }
    std::cout << "Вы угадали!\n";
    std::cout << "Количество попыток: " << attempts << "\n";
}


// 4.2. Поиск последнего значения
int findLast(int arr[], int size, int x) {
    for (int i = size - 1; i >= 0; --i) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

// 4.4. Добавление в массив
int* add(int arr[], int size, int x, int pos) {
    if (pos < 0) {
        pos = 0;
    }
    if (pos > size) {
        pos = size;
    }
    int* result = new int[size + 1];
    for (int i = 0; i < pos; ++i) {
        result[i] = arr[i];
    }
    result[pos] = x;
    for (int i = pos; i < size; ++i) {
        result[i + 1] = arr[i];
    }
    return result;
}

// 4.6. Реверс
void reverse(int arr[], int size) {
    for (int i = 0; i < size / 2; ++i) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

// 4.8. Объединение
int* concat(int arr1[], int size1, int arr2[], int size2) {
    int* result = new int[size1 + size2];
    for (int i = 0; i < size1; ++i) {
        result[i] = arr1[i];
    }
    for (int i = 0; i < size2; ++i) {
        result[size1 + i] = arr2[i];
    }
    return result;
}

// 4.10. Удалить негатив
int* deleteNegative(int arr[], int size, int& result_size) {
    int* result = new int[size];
    result_size = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] >= 0) {
            result[result_size] = arr[i];
            ++result_size;
        }
    }
    return result;
}

//Ввод и вывод для main
void checkInputEnd() {
    if (std::cin.eof()) {
        std::cout << "\nВвод закончился. Выход из программы.\n";
        std::exit(0);
    }
}

// Читает одно целое число. Если ввод неверный, просит повторить.
int inputInt() {
    int value = 0;
    while (!(std::cin >> value) || std::cin.peek() != '\n') {
        checkInputEnd();
        std::cout << "Ошибка! Нужно ввести одно целое число. Повторите ввод: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    std::cin.ignore(10000, '\n');
    return value;
}

// Читает один символ. Если ввод неверный, просит повторить.
char inputChar() {
    char value = 0;
    while (!(std::cin >> value) || std::cin.peek() != '\n') {
        checkInputEnd();
        std::cout << "Ошибка! Нужно ввести один символ. Повторите ввод: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    std::cin.ignore(10000, '\n');
    return value;
}

// Печатает массив
void printArray(int arr[], int size) {
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
        if (i > 0) {
            std::cout << ", ";
        }
        std::cout << arr[i];
    }
    std::cout << "]\n";
}

// Вводит массив с клавиатуры и возвращает его размер.
int inputArray(int arr[], int max_size) {
    std::cout << "Введите размер массива (от 1 до " << max_size << "): ";
    int size = inputInt();
    while (size < 1 || size > max_size) {
        std::cout << "Размер должен быть от 1 до " << max_size
            << ". Повторите ввод: ";
        size = inputInt();
    }
    for (int i = 0; i < size; ++i) {
        std::cout << "arr[" << i << "] = ";
        arr[i] = inputInt();
    }
    std::cout << "Вы ввели массив: ";
    printArray(arr, size);
    return size;
}

// Меню.
void printMenu() {
    std::cout << "\n";
    std::cout << "  Задача 1. Методы:\t\t\t\tЗадача 3. Циклы:\n";
    std::cout << "   1 - Сумма знаков\t\t\t\t11 - Числа наоборот\n";
    std::cout << "   2 - Есть ли позитив\t\t\t\t12 - Степень числа\n";
    std::cout << "   3 - Большая буква\t\t\t\t13 - Одинаковость\n";
    std::cout << "   4 - Делитель\t\t\t\t\t14 - Левый треугольник\n";
    std::cout << "   5 - Многократный вызов\t\t\t15 - Угадайка\n\n";
    std::cout << "  Задача 2. Условия:\t\t\t\tЗадача 4. Массивы:\n";
    std::cout << "   6 - Безопасное деление\t\t\t"
        "16 - Поиск последнего значения\n";
    std::cout << "   7 - Строка сравнения\t\t\t\t17 - Добавление в массив\n";
    std::cout << "   8 - Тройная сумма\t\t\t\t18 - Реверс\n";
    std::cout << "   9 - Возраст\t\t\t\t\t19 - Объединение\n";
    std::cout << "  10 - Вывод дней недели\t\t\t20 - Удалить негатив\n\n";
    std::cout << "   0 - Выход из программы\n\n";
}


int main() {
    std::setlocale(LC_ALL, "Russian");
    std::cout << std::boolalpha;
    int choice = -1;

    do {
        printMenu();
        std::cout << "Введите номер задачи: ";
        choice = inputInt();
        std::cout << "\n";

        switch (choice) {
        case 1: {
            std::cout << "Введите число (минимум 2 цифры): ";
            int x = inputInt();
            while (x > -10 && x < 10) {
                std::cout << "Нужно минимум 2 цифры. Повторите ввод: ";
                x = inputInt();
            }
            std::cout << "Результат: " << sumLastNums(x) << "\n";
            break;
        }
        case 2: {
            std::cout << "Введите число: ";
            int x = inputInt();
            std::cout << "Число положительное? " << isPositive(x) << "\n";
            break;
        }
        case 3: {
            std::cout << "Введите один символ: ";
            char symbol = inputChar();
            std::cout << "Это большая буква от A до Z? "
                << isUpperCase(symbol) << "\n";
            break;
        }
        case 4: {
            std::cout << "Введите первое число: ";
            int a = inputInt();
            std::cout << "Введите второе число: ";
            int b = inputInt();
            std::cout << "Одно число делит другое нацело? "
                << isDivisor(a, b) << "\n";
            break;
        }
        case 5: {
            std::cout << "Введите 5 чисел (по одному в строке):\n";
            std::cout << "Число 1: ";
            int result = inputInt();
            for (int i = 2; i <= 5; ++i) {
                std::cout << "Число " << i << ": ";
                int next = inputInt();
                std::cout << result << "+" << next << " это ";
                result = lastNumSum(result, next);
                std::cout << result << "\n";
            }
            std::cout << "Итого " << result << "\n";
            break;
        }
        case 6: {
            std::cout << "Введите делимое: ";
            int x = inputInt();
            std::cout << "Введите делитель: ";
            int y = inputInt();
            if (y == 0) {
                std::cout << "Делить на 0 нельзя. Результат: "
                    << safeDiv(x, y) << "\n";
            }
            else {
                std::cout << "Результат: " << x << " / " << y << " = "
                    << safeDiv(x, y) << "\n";
            }
            break;
        }
        case 7: {
            std::cout << "Введите первое число: ";
            int x = inputInt();
            std::cout << "Введите второе число: ";
            int y = inputInt();
            std::cout << "Результат: " << makeDecision(x, y) << "\n";
            break;
        }
        case 8: {
            std::cout << "Введите первое число: ";
            int x = inputInt();
            std::cout << "Введите второе число: ";
            int y = inputInt();
            std::cout << "Введите третье число: ";
            int z = inputInt();
            std::cout << "Два числа в сумме дают третье? "
                << sum3(x, y, z) << "\n";
            break;
        }
        case 9: {
            std::cout << "Введите возраст: ";
            int years = inputInt();
            while (years < 0) {
                std::cout << "Возраст не может быть отрицательным. "
                    "Повторите ввод: ";
                years = inputInt();
            }
            std::cout << "Результат: " << age(years) << "\n";
            break;
        }
        case 10: {
            std::cout << "Введите номер дня недели (1-7): ";
            int day = inputInt();
            std::cout << "Результат:\n";
            printDays(day);
            break;
        }
        case 11: {
            std::cout << "Введите число от 0 до 1000: ";
            int x = inputInt();
            while (x < 0 || x > 1000) {
                std::cout << "Число должно быть от 0 до 1000. "
                    "Повторите ввод: ";
                x = inputInt();
            }
            std::cout << "Результат: " << reverseListNums(x) << "\n";
            break;
        }
        case 12: {
            std::cout << "Введите основание степени: ";
            int x = inputInt();
            std::cout << "Введите показатель степени (от 0): ";
            int y = inputInt();
            while (y < 0) {
                std::cout << "Показатель не может быть меньше 0. "
                    "Повторите ввод: ";
                y = inputInt();
            }
            // 2147483647 - наибольшее значение типа int.
            if (std::abs(std::pow(x, y)) > 2147483647) {
                std::cout << "Результат не помещается в тип int.\n";
            }
            else {
                std::cout << "Результат: " << pow(x, y) << "\n";
            }
            break;
        }
        case 13: {
            std::cout << "Введите целое число: ";
            int x = inputInt();
            std::cout << "Все цифры одинаковые? " << equalNum(x) << "\n";
            break;
        }
        case 14: {
            std::cout << "Введите высоту треугольника (от 1 до 100): ";
            int x = inputInt();
            while (x < 1 || x > 100) {
                std::cout << "Высота должна быть от 1 до 100. "
                    "Повторите ввод: ";
                x = inputInt();
            }
            std::cout << "Результат:\n";
            leftTriangle(x);
            break;
        }
        case 15: {
            guessGame();
            break;
        }
        case 16: {
            int arr[100];
            int size = inputArray(arr, 100);
            std::cout << "Введите число для поиска: ";
            int x = inputInt();
            int index = findLast(arr, size, x);
            std::cout << "Результат: " << index << "\n";
            if (index == -1) {
                std::cout << "Такого числа в массиве нет.\n";
            }
            break;
        }
        case 17: {
            int arr[100];
            int size = inputArray(arr, 100);
            std::cout << "Введите число для вставки: ";
            int x = inputInt();
            std::cout << "Введите позицию (от 0 до " << size << "): ";
            int pos = inputInt();
            while (pos < 0 || pos > size) {
                std::cout << "Позиция должна быть от 0 до " << size
                    << ". Повторите ввод: ";
                pos = inputInt();
            }
            int* result = add(arr, size, x, pos);
            std::cout << "Результат: ";
            printArray(result, size + 1);
            delete[] result;
            break;
        }
        case 18: {
            int arr[100];
            int size = inputArray(arr, 100);
            reverse(arr, size);
            std::cout << "Массив после реверса: ";
            printArray(arr, size);
            break;
        }
        case 19: {
            int arr1[100];
            int arr2[100];
            std::cout << "Первый массив:\n";
            int size1 = inputArray(arr1, 100);
            std::cout << "Второй массив:\n";
            int size2 = inputArray(arr2, 100);
            int* result = concat(arr1, size1, arr2, size2);
            std::cout << "Результат: ";
            printArray(result, size1 + size2);
            delete[] result;
            break;
        }
        case 20: {
            int arr[100];
            int size = inputArray(arr, 100);
            int result_size = 0;
            int* result = deleteNegative(arr, size, result_size);
            std::cout << "Результат: ";
            printArray(result, result_size);
            delete[] result;
            break;
        }
        case 0: {
            std::cout << "Выход из программы.\n";
            break;
        }
        default: {
            std::cout << "Такой задачи нет. Введите число от 0 до 20.\n";
            break;
        }
        }
    } while (choice != 0);

    return 0;
}
