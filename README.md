# s21_matrix

## Описание проекта

Этот проект представляет собой библиотеку `matrix.h`, реализующую основные операции с матрицами, включая создание, удаление, сложение, вычитание, умножение, транспонирование, вычисление определителя, получение матрицы алгебраических дополнений и нахождение обратной матрицы. Библиотека написана на языке Си (стандарт C11) и собирается с помощью компилятора `gcc`.

## Структура проекта

- **functions/** — исходный код библиотеки
- **tests/** — юнит-тесты для проверки корректности работы функций
- **s21_matrix.h** — заголовочный файл с определением структуры и функций
- **Makefile** — makefile для сборки проекта, запуска тестов и генерации отчёта по покрытию кода

## Основной функционал

Реализованы следующие функции работы с матрицами (с префиксом `s21_`):

- **Создание и удаление матрицы**: `s21_create_matrix`, `s21_remove_matrix`
- **Операции с матрицами**:
  - Сравнение матриц: `s21_eq_matrix`
  - Сложение и вычитание: `s21_sum_matrix`, `s21_sub_matrix`
  - Умножение матриц и умножение на число: `s21_mult_matrix`, `s21_mult_number`
  - Транспонирование матрицы: `s21_transpose`
  - Вычисление определителя: `s21_determinant`
  - Построение матрицы алгебраических дополнений: `s21_calc_complements`
  - Нахождение обратной матрицы: `s21_inverse_matrix`

Библиотека построена по принципам структурного программирования и использует POSIX-совместимые функции стандарта POSIX.1-2017.

## Сборка и тестирование

### Требования

- Компилятор `gcc` (стандарт C11)
- Библиотека `Check` для юнит-тестирования
- Инструмент `gcov` для генерации отчётов покрытия

### Сборка проекта

Выполните следующие команды в корневой директории проекта:

- **Сборка библиотеки**:
  ```bash
  make s21_matrix.a
Собирает статическую библиотеку s21_matrix.a в корневой директории.

- **Сборка и запуск тестов**:

  ```bash
  make test
  ```

Компилирует и запускает юнит-тесты для проверки функций библиотеки.

- **Генерация отчёта покрытия**:

  ```bash
  make gcov_report
  ```

Создаёт HTML-отчёт о покрытии кода тестами в директории gcov_report.

- **Очистка собранных файлов**:

  ```bash
  make clean
  ```
Удаляет все временные и скомпилированные файлы, создавая чистую рабочую директорию.

Покрытие кода тестами

Все функции библиотеки покрыты юнит-тестами с использованием библиотеки Check, и покрытие кода тестами должно составлять не менее 80% для каждой функции. Проверить покрытие можно через gcov после запуска make gcov_report.
Примечания по реализации

* Все функции реализованы в соответствии с соглашениями о стиле кода Google.
* Используются только актуальные и безопасные функции и конструкции языка C11.
* Функции обеспечивают точность дробной части до 6 знаков после запятой.

