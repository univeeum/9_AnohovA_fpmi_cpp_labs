# Лабораторная работа №7. Класс Vector

Данная задача немного отличется от остальных. В рамках данной лабораторной работы вам предстоит написать собственный класс `Vector`, который будет являться упрощённым аналогом шаблонного класса `std::vector`. Вам **запрещено использовать стандартные контейнеры и умные указатели**, поэтому _аккуратно работайте с памятью_. Текст с заданием находится в файле [lab7_class_vector.pdf](lab7_class_vector.pdf).

В отличие от других лабораторных работ здесь есть автоматическое тестирование написанной вами программы. **Обязательным условием сдачи этой лабораторной работы** является успешное прохождение всех этих тестов.

## Сборка проекта и запуск тестов

Данные команды будут работать на Linux и OSX.

> Если у вас стоит ОС Windows, я рекомендую использовать WSL для сборки проекта (там также будут работать команды ниже).

### Создане папки build
```shell
# В директории 'lab7_class_vector/'
mkdir build
cd build/
```

### Запуск cmake

> Перед выполнением следующей команды, проверьте, что вы создали папку **build** в директории с самой задачей, а не в корне репозитория.

```shell
cmake ..
```

Если вы на этом шаге получите странные ошибки, то ещё раз напомню, чтобы вы проверили, что вы создали папку **build** в директории с самой задачей, а не в корне репозитория!

При этом будет выведена некоторая служебная информация, в частности используемый компилятор (ниже приведён пример вывода, у вас может отличаться):
```
-- The C compiler identification is GNU 14.2.0
-- The CXX compiler identification is GNU 14.2.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.5s)
-- Generating done (0.0s)
-- Build files have been written to: /home/egor/fpmi_cpp_labs/semester_1/lab7_class_vector/build
```

> Для корректной сборки необходим `g++` версии не ниже 7.1 или `clang++` версии не ниже 5.0.

### Задача multiplication

Для разминки и тренировки сборки проекта вам таже будет предложена задача multiplication, в которой нужно будет реализовать функцию 
**Multiply** умножения двух целых чисел $a$ и $b$ (файл [multiplication.h](multiplication/multiplication.h)). Эта задача будет разобрана на занятии.

Соберём нашу задачу:
```
make test_multiplication
```

Теперь в папке **build** есть исполняемый файл _test_multiplication_, который надо запустить:
```
./test_multiplication
```

### Тестирование с санитайзерами
Обращаю внимание, что тестирование будет осуществляться с включенными санитайзерами, которые проверяют, корректно ли вы работаете с памятью, нет ли у вас неопределённого поведения в программе и т.п. Чтобы осущетвить такую сборку, нужно выполнить следующие команды:
```bash
# В директории 'lab7(class_vector)/'
mkdir adan_build
cd asan_build
cmake -DCMAKE_BUILD_TYPE=ASAN ..
make test_multiplication
```
После этого в папке **asan_build** также появится исполняемый файл _test_multiplication_.

> Если вы реализуете решение в этой задаче просто как `a * b` (без приведения к `int64_t`), то тесты в asan-сборке должны упасть с соответствующим сообщением о переполнении.

### Задача Vector

В этой задаче вам разрешено менять только файлы [vector_impl.h](vector/vector_impl.h) и [vector_impl.cpp](vector/vector_impl.cpp), в которых будет ваша реализация класса `Vector`. Остальные файлы трогать не нужно, т.к. сборка может сломаться. Тесты к задаче находятся в файле [test.cpp](vector/test.cpp). 

Сборка и запуск программы осуществляются аналогично задаче multiplication, за исключением того, что вы собираете не test_multiplication, а test_vector:
```bash
# из директорий build или asan_build
make test_vector
./test_vector
```

