#include <Python.h>
#include <float.h>

/**
 * print_python_list - prints some basic info about Python lists
 * @p: Python object
 */
void print_python_list(PyObject *p)
{
    PyListObject *list = (PyListObject *)p;
    Py_ssize_t size = PyList_Size(p);
    Py_ssize_t i;

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %li\n", size);
    printf("[*] Allocated = %li\n", list->allocated);

    for (i = 0; i < size; i++)
    {
        printf("Element %li: %s\n", i, Py_TYPE(PyList_GetItem(p, i))->tp_name);
    }
}

/**
 * print_python_bytes - prints some basic info about Python bytes objects
 * @p: Python object
 */
void print_python_bytes(PyObject *p)
{
    PyBytesObject *bytes = (PyBytesObject *)p;
    Py_ssize_t size = PyBytes_Size(p);
    char *str = PyBytes_AsString(p);
    Py_ssize_t i;

    printf("[*] Python bytes info\n");
    if (!PyBytes_Check(p))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }
    printf("  size: %li\n", size);
    printf("  trying string: %s\n", str);

    if (size > 10)
        size = 10;
    printf("  first %li bytes: ", size);
    for (i = 0; i < size; i++)
    {
        printf("%02x", (unsigned char)str[i]);
        if (i < size - 1)
            printf(" ");
    }
    printf("\n");
}

/**
 * print_python_float - prints some basic info about Python float objects
 * @p: Python object
 */
void print_python_float(PyObject *p)
{
    PyFloatObject *floatobj = (PyFloatObject *)p;
    double value = floatobj->ob_fval;

    printf("[*] Python float info\n");
    if (!PyFloat_Check(p))
    {
        printf("  [ERROR] Invalid Float Object\n");
        return;
    }

    printf("  value: %f\n", value);
}
