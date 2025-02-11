/// \file dialog.h
/// \brief Заголовочный файл, который определяет функции и диалоги для взаимодействия с пользователем.

#ifndef INC_1_DIALOG_H
#define INC_1_DIALOG_H

#include "functions.h"

#include <iostream>
#include <string>

/// \namespace Prog1
/// \brief Пространство имен, содержащее функции и диалоги для пользовательского взаимодействия.

namespace Prog1 {

    using std::string, std::cin, std::cout, std::endl;

/// \def NUMBER_OF_FUNCTIONS
/// \brief Макрос, задающий количество функций, используемых в диалогах.
#define NUMBER_OF_FUNCTIONS 4

    /// \brief Выполняет промежуточный диалог с пользователем.
    ///
    /// Использует массив строк для представления вариантов выбора и выполняет соответствующую функцию.
    ///
    /// \param options Массив строк с возможными вариантами выбора для пользователя.
    /// \param number Количество доступных вариантов.
    /// \return Целое число, указывающее на выбранную пользователем опцию.
    int intermediate_dialogue(const string [], int);

    /// \brief Основной диалог с пользователем.
    ///
    /// Определяет основной интерфейс взаимодействия с пользователем, предлагая различные действия.
    void main_dialog();

    /// \brief Обработчик выхода из диалога.
    ///
    /// \return Короткое целое число, указывающее результат обработки команды выхода.
    inline short d_exit();

    /// \brief Обработчик операции объединения.
    ///
    /// \return Короткое целое число, указывающее результат обработки команды объединения.
    inline short d_join();

    /// \brief Обработчик операции вычисления абсолютного значения.
    ///
    /// \return Короткое целое число, указывающее результат выполнения команды абсолютного значения.
    inline short d_absolute();

    /// \brief Обработчик операции вычисления относительного значения.
    ///
    /// \return Короткое целое число, указывающее результат выполнения команды относительного значения.
    inline short d_relative();

    /// \brief Обработчик операции приведения к относительному значению.
    ///
    /// \return Короткое целое число, указывающее результат выполнения команды относительному значению.
    inline short d_relativize();
}
#endif //INC_1_DIALOG_H
