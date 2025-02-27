Для редокументации кода (при желании его изменить) можно пользоваться следующими подсказками
- @param <name> — описание параметра функции;
- @return — описание возвращаемого значения;
- @brief — краткое описание;
- @details — подробное описание;
- @author — автор функции или файла;
- @version — версия;
- @date — дата последнего изменения;
- @warning или @note — важные замечания или предупреждения.

---

# Проект: Утилиты для работы с путями файловой системы

## Описание

Этот проект предоставляет набор функций для работы с путями файловой системы, включая:

1. join - конкатенация базового пути и относительного пути.
2. absolute - преобразование относительного пути в абсолютный.
3. relative - преобразование абсолютного пути в относительный, и наоборот.
4. relativize - определение расположения одного абсолютного пути относительно другого.

## Функциональность

- join(base, relative):
   - Входные данные: базовый путь base (может быть относительный или абсолютный), относительный путь relative.
   - Возвращает: конкатенацию путей или ошибку, если relative не является относительным.

- absolute(path):
   - Входные данные: относительный или абсолютный путь path.
   - Возвращает: абсолютный путь, преобразовав path, если необходимо.

- relative(path):
   - Входные данные: абсолютный или относительный путь path.
   - Возвращает: относительный путь относительно текущего рабочего каталога, или очищает путь, если path уже относительный.

- relativize(base, target):
   - Входные данные: два абсолютных пути base и target.
   - Возвращает: относительное расположение target относительно base, или ошибку, если любой из путей не абсолютный.

## Требования

- Поддержка различных операционных систем с использованием разделительных символов:
  - Linux, macOS: /
  - Windows: \\

  У реализации используется директивы препроцессора: #ifdef linux, #ifdef APPLE, #ifdef _WIN32.

## Установка

1. Клонируйте репозиторий:

   git clone https://git.dozen.mephi.ru/oop2024/b23505_volkov.ed.git

2. Настройте и выполните сборку проекта (например, с использованием CMake или другой системы сборки).
3. Убедитесь, что ваш проект правильно ссылается на все зависимости и пакеты.

## Использование

Примеры использования функций находятся в файле тестов или могут быть добавлены ниже. Убедитесь, что все функции работают корректно в вашей среде разработки.

## Вклад

Если вы хотите внести свой вклад в проект, создайте pull request или откройте issue для обсуждения изменений и улучшений.

## Лицензия

Для проекта использовалась MIT License (см. подробнее в файле LICENSE)

## Контакты

Если у вас возникнут вопросы, свяжитесь со мной по электронной почте: egor.volkov2005@yandex.ru

---