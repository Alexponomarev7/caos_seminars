#include <Python.h>

static PyObject *
do_something(PyObject *self, PyObject *args) {
    PyErr_SetString(PyExc_RuntimeError, "Not implemented yet");
    return NULL;
}

static PyMethodDef methods[] = {
    {
        // имя Python-функции 
        .ml_name = "do_something",
        // указатель на Си-функцию
        .ml_meth = do_something,
        // флаги использования Си-функции
        .ml_flags = METH_VARARGS,
        // строка описания, выдается функцией help()
        .ml_doc = "Do something very useful"
    },
    // признак конца массива описаний методов
    {NULL, NULL, 0, NULL}
};

static PyModuleDef moduleDef = {
	// ссылка на RTTI, поскольку Си не является ООП-языком
    .m_base = PyModuleDef_HEAD_INIT,
    // имя модуля
    .m_name = "app",
    // размер дополнительной памяти для хранения состояния модуля в
    // случае использования нескольких интерпретаторов, либо -1,
    // если не планируется использование PyModule_GetState
    .m_size = -1,
    // указатель на список методов (функций) модуля, может быть NULL
    .m_methods = methods,
};

