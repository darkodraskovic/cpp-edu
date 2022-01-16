#include <iostream>

#include "PyHelper.hpp"

int main(int argc, char* argv[]) {
    CPyInstance pyInstance;

    PyRun_SimpleString("print('Hello World from Embedded Python!!!')");

    CPyObject p;
    p = PyLong_FromLong(50);
    printf_s("Value =  %ld\n", PyLong_AsLong(p));

    CPyObject pName = PyUnicode_FromString("pyemb");
    // import the module and return an module object handle
    CPyObject pModule = PyImport_Import(pName);

    if(pModule) {
        CPyObject pFunc = PyObject_GetAttrString(pModule, "getInteger");
        if(pFunc && PyCallable_Check(pFunc)) {
            CPyObject pValue = PyObject_CallObject(pFunc, NULL);
            printf_s("C: getInteger() = %ld\n", PyLong_AsLong(pValue));
        }
        else {
            printf("ERROR: function getInteger()\n");
        }

    }
    else {
        printf_s("ERROR: Module not imported\n");
    }

    return 0;
}
