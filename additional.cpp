/// \file
/// \brief Заголовочный файл, содержащий функции для работы со строками и текущим каталогом.

#include "additional.h"

/// \namespace Prog1
/// \brief Пространство имен для основных функций работы со строками и каталогами.

namespace Prog1 {

    /** \brief Эта функция считывает строку из стандартного ввода (std::cin).
     \return Указатель на динамически выделенную строку в случае успешного ввода.
             Если ввод не удался (например, достигнут EOF или произошла ошибка),
             возвращается nullptr. Если не удалось корректно выделить память, обработчик исключений
             увидит ошибку и с помощью блока try catch корректно ее обработает, после чего программа
             продолжит работу

     \note Пользователь должен освободить выделенную память после использования.
          Например, использовать delete[] для освобождения.
    */
    char* input_string() {
        std::string result;
        getline(std::cin, result);
        if (std::cin.eof())
            return nullptr;
        if (std::cin.fail()) {
            std::cin.clear();
            return nullptr;
        }
        try {
            char* buffer = new char[result.size() + 1];
            std::copy(result.begin(), result.end(), buffer);
            buffer[result.size()] = '\0';
            return buffer;
        } catch (const std::bad_alloc& e) {
            std::cerr << "Failed to allocate memory: " << e.what() << std::endl;
            throw;
        }
    }

    /** \brief Получает текущий рабочий каталог.

     Эта функция получает текущий рабочий каталог с использованием системного вызова getcwd.
     \return Строка, содержащая путь к текущему рабочему каталогу. Возвращает пустую строку
             в случае ошибки, например, если размер буфера недостаточен и ошибка не связана
             с ERANGE.

     \exception Если возникла ошибка, кроме ERANGE, будет возвращена пустая строка.
    */

    std::string get_current_dir() {
        std::vector<char> buffer(BUFSIZ);
        while (true) {
            if (getcwd(buffer.data(), buffer.size()) != nullptr) {
                return { std::string(buffer.data()) };
            }
            if (errno != ERANGE) {
                return "";
            }
            buffer.resize(buffer.size() + BUFSIZ);
        }
    }
}
