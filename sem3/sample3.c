#include <stdio.h>
#include <Python.h>
#include <stdint.h>
#include "module.h"

/**
static PyObject *
create_module() {
    // NULL в качестве возвразаемого значения любой функции,
    // которая должна возвращать PyObject*, означает 
    // исключительную ситуацию
    PyErr_SetString(PyExc_RuntimeError, "Not implemented yet");
    return NULL;
}  
**/

int main(int argc, char *argv[]) {
	PyObject *module = PyModule_Create(&moduleDef);
    
    // Добавляем в таблицу имя встроенного модуля
    PyImport_AppendInittab("app", create_module);
   
	FILE* fp = fopen(argv[1], "r");
 
    // Регистрация встроенных модулей должна быть сделана 
    // раньше, чем PyInitialize
    PyInitialize();
    PyRun_SimpleFile(fp, argv[1]);
    Py_Finalize();
    fclose(fp);
}

