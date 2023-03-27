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
    PyBytesObject *bytes;

    printf("[.] bytes object info\n");
    if (!PyBytes_Check(p))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    bytes = (PyBytesObject *) p;
    printf("  size: %ld\n", PyBytes_Size(p));
    printf("  trying string: %s\n", PyBytes_AsString(p));
    printf("  first %ld bytes:", PyBytes_Size(p) + 1 > 10 ? 10 : PyBytes_Size(p) + 1);
    for (Py_ssize_t i = 0; i < PyBytes_Size(p) + 1 && i < 10; i++)
        printf(" %02x", (unsigned char) bytes->ob_sval[i]);
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
