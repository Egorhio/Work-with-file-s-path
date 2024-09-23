/// \file functions.cpp
/// \brief Реализация перегрузок функций для обработки путей.

#include "functions.h"

/// \namespace Prog1
/// \brief Пространство имен для функций работы с путями.
namespace Prog1 {

    /// \brief Соединяет базовый и относительный пути в один строковый путь.
    ///
    /// \param basePath Базовый путь в виде C-строки.
    /// \param relativePath Относительный путь в виде C-строки.
    /// \return Соединенный путь в виде строки.
    std::string join(const char *basePath, const char *relativePath) {
        return join(std::string(basePath), std::string(relativePath));
    }

    /// \brief Преобразует относительный путь в абсолютный.
    ///
    /// \param relativePath Относительный путь в виде C-строки.
    /// \return Абсолютный путь в виде строки.
    std::string absolute(const char *relativePath) {
        return absolute(std::string(relativePath));
    }

    /// \brief Преобразует абсолютный путь в относительный.
    ///
    /// \param absolutePath Абсолютный путь в виде C-строки.
    /// \return Относительный путь в виде строки.
    std::string relative(const char *absolutePath) {
        return relative(std::string(absolutePath));
    }

    /// \brief Определяет относительное расположение одного пути относительно другого.
    ///
    /// \param basePath Базовый путь в виде C-строки.
    /// \param path Второй путь в виде C-строки.
    /// \return Относительное расположение второго пути относительно первого в виде строки.
    std::string relativize(const char *basePath, const char *path) {
        return relativize(std::string(basePath), std::string(path));
    }

}