/// \file functions.cpp
/// \brief Реализация функций для работы с файловыми путями.
///
/// Этот файл содержит реализацию функций для манипуляции файловыми путями,
/// определенных в заголовочном файле `functions.h`.

#include "functions.h"

namespace Prog1 {
    using std::string;
    using std::cin;
    using std::cout;

    /// \brief Соединяет базовый путь и относительный путь.
    /// \param basePath Базовый путь.
    /// \param relativePath Относительный путь.
    /// \return Соединенный путь.
    ///
    /// Если относительный путь начинается с разделителя, функция возвращает сообщение об ошибке.
    string join(const string &basePath, const string &relativePath) {
        if (relativePath.empty() || relativePath[0] == pathSeparator) {
            std::cerr << "ERROR";
            return "\nThe second argument must be a relative path!!!";
        }
        if (basePath.back() == pathSeparator) {
            return basePath + relativePath;
        } else {
            return basePath + pathSeparator + relativePath;
        }
    }

    /// \brief Преобразует относительный путь в абсолютный.
    /// \param relativePath Относительный путь.
    /// \return Абсолютный путь.
    ///
    /// Если путь уже абсолютный, возвращает его без изменений.
    string absolute(const string &relativePath) {
        if (relativePath.empty() || relativePath[0] == pathSeparator) {
            return relativePath;
        }
        string currentDir = get_current_dir();
        if (currentDir.back() != pathSeparator) {
            currentDir += pathSeparator;
        }
        return currentDir + relativePath;
    }

    /// \brief Преобразует абсолютный путь в относительный.
    /// \param absolutePath Абсолютный путь.
    /// \return Относительный путь.
    ///
    /// Если путь уже относительный, возвращает его без изменений.
    string relative(const string &absolutePath) {
        if (absolutePath.empty() || absolutePath[0] != pathSeparator) {
            return absolutePath;
        }
        string currentDir = get_current_dir();
        if (currentDir.back() != pathSeparator) {
            currentDir += pathSeparator;
        }
        size_t i = 0;
        while (i < absolutePath.size() && i < currentDir.size() && absolutePath[i] == currentDir[i]) {
            i++;
        }
        if (i == 0) {
            return absolutePath;
        }
        string result;
        for (size_t j = i; j < currentDir.size(); j++) {
            if (currentDir[j] == pathSeparator) {
                result += "..";
                result += pathSeparator;
            }
        }
        result += absolutePath.substr(i);
        return result;
    }

    /// \brief Преобразует путь относительно базового пути.
    /// \param basePath Базовый путь.
    /// \param path Путь для преобразования.
    /// \return Путь относительно базового.
    ///
    /// Выдает сообщение об ошибке, если оба пути не являются абсолютными.
    string relativize(const string &basePath, const string &path) {
        if (basePath.empty() || path.empty() || basePath[0] != pathSeparator || path[0] != pathSeparator) {
            std::cerr << "ERROR: Both paths must be absolute and start with a path separator." << std::endl;
            return "\nOne of the arguments is not an absolute path!";
        }
        auto mismatchPair = std::mismatch(basePath.begin(), basePath.end(), path.begin());
        size_t i = std::distance(basePath.begin(), mismatchPair.first);
        if (i == 0) {
            return path;
        }
        size_t upLevels = std::count(mismatchPair.first, basePath.end(), pathSeparator);
        string result;
        for (size_t j = 0; j < upLevels; j++) {
            result += "..";
            result += pathSeparator;
        }
        result += path.substr(i);
        return result;
    }
}