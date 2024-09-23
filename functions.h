/// \file functions.h
/// \brief Заголовочный файл, определяющий функции для работы с файловыми путями.
///
/// Этот файл содержит объявления функций для манипуляции файловыми путями, а также
/// определяет разделитель пути в зависимости от операционной системы. Используется
/// в пространстве имен `Prog1`.

#ifndef INC_1_FUNCTIONS_H
#define INC_1_FUNCTIONS_H

#ifdef _WIN32
const char pathSeparator = '\\'; ///< Разделитель для 32-битной системы Windows.
#elif defined(_WIN64)
const char pathSeparator = '\\';  ///< Разделитель для 64-битной системы Windows.
#elif defined(__linux__) || defined(__APPLE__)
const char pathSeparator = '/'; ///< Разделитель для систем Linux и MacOS.
#else
#error "Неизвестная операционная система" ///< Ошибка компиляции для неизвестной ОС.
#endif

#include <iostream>
#include <string>
#include <algorithm>
#include "additional.h"

namespace Prog1 {
    /// \brief Соединяет базовый путь и относительный путь.
    /// \param basePath Базовый путь.
    /// \param relativePath Относительный путь.
    /// \return Соединенный путь.
    std::string join(const std::string &basePath, const std::string &relativePath);

    /// \brief Преобразует относительный путь в абсолютный.
    /// \param relativePath Относительный путь.
    /// \return Абсолютный путь.
    std::string absolute(const std::string &relativePath);

    /// \brief Преобразует абсолютный путь в относительный.
    /// \param absolutePath Абсолютный путь.
    /// \return Относительный путь.
    std::string relative(const std::string &absolutePath);

    // \brief Преобразует путь, относительно базового пути.
    /// \param basePath Базовый путь.
    /// \param path Путь для преобразования.
    /// \return Путь, относительно базового.
    std::string relativize(const std::string &basePath, const std::string &path);

    /// \overload string join(const char *basePath, const char *relativePath);
    std::string join(const char *basePath, const char *relativePath);

    /// \overload string absolute(const char *relativePath);
    std::string absolute(const char *relativePath);

    /// \overload string relative(const char *absolutePath);
    std::string relative(const char *absolutePath);

    /// \overload string relativize(const char *basePath, const char *path);
    std::string relativize(const char *basePath, const char *path);
}

#endif //INC_1_FUNCTIONS_H


//Куда клонить библиотеку
//как добавить в target testfile.cpp
//нужно ли создавать testfile.hpp
