#pragma once

#include <Python.h>

class CPyInstance {
public:
    CPyInstance() {
        Py_Initialize();
    }

    ~CPyInstance() {
        Py_Finalize();
    }
};


class CPyObject {
private:
    PyObject *p_;
public:
    CPyObject() : p_(NULL) {}

    CPyObject(PyObject* p) : p_(p) {}

    PyObject* getObject() {
        return p_;
    }

    PyObject* setObject(PyObject* p) {
        return (p_= p);
    }

    PyObject* AddRef() {
        if(p_) {
            Py_INCREF(p_);
        }
        return p_;
    }

    void Release() {
        if(p_) {
            Py_DECREF(p_);
        }

        p_= NULL;
    }

    bool is() const {
        return p_ ? true : false;
    }

    PyObject* operator->() {
        return p_;
    }

    // operators
    PyObject* operator=(PyObject* p) {
        p_ = p;
        return p_;
    }

    operator PyObject*() {
        return p_;
    }

    // conversion operators
    operator bool() const {
        return p_ ? true : false;
    }

    ~CPyObject() {
        Release();
    }
};
