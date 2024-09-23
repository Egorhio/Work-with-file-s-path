/// \file dialog.cpp
/// \brief Реализация функций взаимодействия с пользователем для обработки путей.

#include "dialog.h"

/// \namespace Prog1
/// \brief Пространство имен, содержащее функции и диалоги для пользовательского взаимодействия.
namespace Prog1 {

    /// \brief Основной диалог с пользователем.
    ///
    /// Формирует меню выбора команд, предлагает пользователю выбрать одну из опций,
    /// и вызывает соответствующую функцию.
    void main_dialog() {
        short(*fptr[])() = {d_exit, d_join, d_absolute, d_relative, d_relativize};
        const string msgs[] = {
                "0. Quit",
                "1. Join (path concatenation)",
                "2. Absolute (relative -> absolute path (base path))",
                "3. Relative (absolute -> relative (relative to the current working directory))",
                "4. Relativize (two absolute paths -> location of the second path relative to the first)",
        };
        const int NMsgs = sizeof(msgs) / sizeof(msgs[0]);
        while (true) {
            cout << "----- MENU ----- " << endl;
            int rc = intermediate_dialogue(msgs, NMsgs);
            if (!fptr[rc]()) break;
        }
    }

    /// \brief Промежуточный диалог для выбора опций пользователем.
    ///
    /// Отображает список доступных опций и запрашивает выбор пользователя.
    ///
    /// \param msgs Массив строк с сообщениями для пользователя.
    /// \param N Количество сообщений.
    /// \return Номер выбранной пользователем опции.
    int intermediate_dialogue(const string msgs[], int N) {
        for (size_t i = 0; i < N; ++i)
            cout << msgs[i] << endl;
        cout << "Make your choice: --> ";
        int num = getNumber<int>(0, NUMBER_OF_FUNCTIONS);
        return num;
    }

    /// \brief Обработчик команды выхода из программы.
    ///
    /// \return Возвращает 0 для выхода.
    short d_exit() {
        return 0;
    }

    /// \brief Обработчик операции соединения путей.
    ///
    /// Запрашивает у пользователя базовый и относительный путь, и выводит результат их соединения.
    ///
    /// \return 1 при успешном выполнении операции, 0 если произошла ошибка.
    short d_join() {
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Enter base path: ";
        const char* basePath = input_string();
        if (basePath == nullptr) {
            cout << "EOF" << endl;
            return 0;
        }
        cout << "Enter relative path: ";
        const char* relativePath = input_string();
        if (relativePath == nullptr) {
            delete[] basePath;
            cout << "EOF" << endl;
            return 0;
        }
        cout << "Result: " << join(basePath, relativePath) << endl;
        delete[] basePath;
        delete[] relativePath;
        return 1;
    }

    /// \brief Обработчик операции преобразования относительного пути в абсолютный.
    ///
    /// \return 1 при успешном выполнении операции, 0 если произошла ошибка.
    short d_absolute() {
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Enter relative path: ";
        const char* relativePath = input_string();
        if (relativePath == nullptr) {
            cout << "EOF" << endl;
            return 0;
        }
        cout << "Result: " << absolute(relativePath) << endl;
        delete[] relativePath;
        return 1;
    }

    /// \brief Обработчик операции преобразования абсолютного пути в относительный.
    ///
    /// \return 1 при успешном выполнении операции, 0 если произошла ошибка.
    short d_relative() {
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Enter absolute path: ";
        const char* basePath = input_string();
        if (basePath == nullptr) {
            cout << "EOF" << endl;
            return 0;
        }
        cout << "Result: " << relative(basePath) << endl;
        delete[] basePath;
        return 1;
    }

    /// \brief Обработчик операции определения относительного расположения одного абсолютного пути относительно другого.
    ///
    /// \return 1 при успешном выполнении операции, 0 если произошла ошибка.
    short d_relativize() {
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Enter first absolute path: ";
        const char* basePath1 = input_string();
        if (basePath1 == nullptr) {
            cout << "EOF" << endl;
            return 0;
        }
        cout << "Enter second absolute path: ";
        const char* basePath2 = input_string();
        if (basePath2 == nullptr) {
            delete[] basePath1;
            cout << "EOF" << endl;
            return 0;
        }
        cout << "Result: " << relativize(basePath1, basePath2) << endl;
        delete[] basePath1;
        delete[] basePath2;
        return 1;
    }
}
