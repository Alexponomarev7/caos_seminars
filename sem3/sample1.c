#define PY_SSIZE_T_CLEAN

#include <Python.h>
#include <stdio.h>

int* CreateNxNArray(PyObject* l, size_t len) {
	printf("Creating an %dx%d array\n", len, len);

	int* arr = (int* )malloc(sizeof(int) * len * len);

	for (int i = 0; i < len; ++i){
		PyObject* list = PyList_GetItem(l, i);
		Py_ssize_t realListSize = PyList_Size(list);
		printf("lsize: %d\n", realListSize);
		for (int j = 0; j < len; ++j) {
			PyObject* el = PyList_GetItem(list, j);
			arr[j+i*len] = PyFloat_AsDouble(el);
			printf("%d at index %d\n", arr[j+i*len], j+i*len);
		}
	}

	return arr;
}


void DisplaySquareMatrix(int* arr, size_t len) {
	for(int i = 0; i<len*len; ++i) {
			printf("%d ", arr[i]);
			printf(i%len==len-1 ?"\n" :"");
	}

	printf("\n");

}

int* SquaredMatrixMultiplication(int* arr1, int* arr2, size_t len)
{
	// initialize the matrix with zeros;

	int* res = (int*)malloc(sizeof(int)*len*len);

	for(int i = 0; i<len*len; ++i)
		res[i] = 0;

	for(int i = 0; i < len; ++i)
		for(int j = 0; j < len; ++j)
			for (int k = 0; k < len; ++k)
				res[j+i*len] += arr1[k+i*len]*arr2[j+k*len];
	printf("Multiplication result: \n");
	DisplaySquareMatrix(res, len);
	return res;

}

PyObject* ConvertArrToPyList(int* res, size_t len) {

	PyObject* plist = PyList_New(len);

	for(int i = 0; i < len; ++i) {
		PyObject* plist1 = PyList_New(len);
		for (int j = 0; j < len; ++j) {
			PyList_SetItem(plist1, j, PyLong_FromLong(res[j+i*len]));
		}
		PyList_SetItem(plist, i, plist1);
	}

	return plist;

}

static PyObject * do_something(PyObject *self, PyObject *args) {

	PyObject* list1;
	PyObject* list2;

	PyObject* initial_length;

	printf("running module\n");


	if (! PyArg_ParseTuple(args, "lOO", &initial_length, &list1, &list2) )
		return NULL;

	// this works
	PyObject* long_length = PyLong_FromLong((long)initial_length);
	size_t length = PyLong_AsSize_t(long_length);

	// this crashes
	//size_t length = PyLong_AsSize_t(initial_length);
	int* arr1 = CreateNxNArray(list1, length);
	int* arr2 = CreateNxNArray(list2, length);

	int* res = SquaredMatrixMultiplication(arr1, arr2, length);
	PyObject* result_list = ConvertArrToPyList(res, length);

	free(arr1);
	free(arr2);
	free(res);

	return result_list;

}

static PyMethodDef methods[] = {
    {// имя Python-функции
     .ml_name = "do_something",
     // указатель на Си-функцию
     .ml_meth = do_something,
     // флаги использования Си-функции
     .ml_flags = METH_VARARGS,
     // строка описания, выдается функцией help()
     .ml_doc = "Do something very useful"},
    // признак конца массива описаний методов
    {NULL, NULL, 0, NULL}
};

PyModuleDef moduleDef = {
    // ссылка на RTTI, поскольку Си не является ООП-языком
    .m_base = PyModuleDef_HEAD_INIT,
    // имя модуля
    .m_name = "my_great_module",
    // размер дополнительной памяти для хранения состояния модуля в
    // случае использования нескольких интерпретаторов, либо -1,
    // если не планируется использование PyModule_GetState
    .m_size = -1,
    // указатель на список методов (функций) модуля, может быть NULL
    .m_methods = methods,
};

PyMODINIT_FUNC PyInit_my_great_module()
{
return PyModule_Create(&moduleDef);

}
