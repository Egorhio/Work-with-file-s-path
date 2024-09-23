/// \file additional.h
/// \brief Заголовочный файл, содержащий функции и шаблоны для обработки строк и чисел, а также получения текущего рабочего каталога.

#ifndef INC_1_ADDITIONAL_H
#define INC_1_ADDITIONAL_H

#include <iostream>
#include <string>
#include <limits>
#include <unistd.h>
#include <vector>

/// \namespace Prog1
/// \brief Пространство имен, содержащее основные функции для работы со строками и переменными.

namespace Prog1 {

    /// \brief Вводит строку из стандартного ввода.
    ///
    /// \return Указатель на динамически выделенную строку или nullptr в случае сбоя.
    char *input_string();

    /// \brief Получает текущий рабочий каталог.
    ///
    /// \return Строка с путем к текущему рабочему каталогу или пустая строка при ошибке.
    std::string get_current_dir();

    /** \brief Считывает число из стандартного ввода с проверкой диапазона.

     Эта шаблонная функция считывает значение указанного типа из стандартного ввода.
     Она гарантирует, что вводимое значение находится в указанном диапазоне.

     \tparam N Тип числа, который будет считан. Например, int, double.
     \param min Минимально допустимое значение (по умолчанию — минимальное значение для данного типа).
     \param max Максимально допустимое значение (по умолчанию — максимальное значение для данного типа).

     \return Введенное число, если оно соответствует условиям.
     \exception std::runtime_error Выбрасывается, если происходит достижение EOF.
    */
    template<typename N>
    N getNumber(N min = std::numeric_limits<N>::lowest(), N max = std::numeric_limits<N>::max()) {
        N num;
        while (true) {
            if (!(std::cin >> num)) {
                if (std::cin.eof())
                    throw std::runtime_error("Failed to read number: EOF");
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else if (num < min || num > max) {
                std::cout << "Number out of range, repeat" << std::endl;
            } else {
                return num;
            }
            std::cout << "Invalid input; repeat please!" << std::endl;
        }
    }
}

#endif //INC_1_ADDITIONAL_H
