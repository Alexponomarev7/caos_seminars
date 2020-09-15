#include <stdio.h>
// В этом заголовочном файле собран почти весь API Python
#include <Python.h>

int main(int argc, char *argv[])
{
    // Открытие файла на чтение
    FILE* fp = fopen(argv[1], "r");
    // Инициализация интерпретатора Python
    Py_Initialize();
    // Выполнение файла
    PyRun_SimpleFile(fp, argv[1]);
    // Завершение работы интерпретатора
    Py_Finalize();
    // Закрытие файла
    fclose(fp);
}

