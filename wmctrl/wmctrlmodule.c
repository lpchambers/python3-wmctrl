#include <Python.h>

static PyObject *wmctrl_list_windows(PyObject *self, PyObject *args) {
    const char *command;
    int sts;
    
    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    sts = system(command);
    return PyLong_FromLong(sts);    
}

static PyMethodDef WmctrlMethods[] = {
    {"list_windows", wmctrl_list_windows, METH_VARARGS,
     "List List windows managed by the window manager."},
    // METH_NOARGS
    {NULL, NULL, 0, NULL}  /* Sentinel */
};

static struct PyModuleDef wmctrlmodule = {
    PyModuleDef_HEAD_INIT,
    "wmctrl",      // name
    NULL,          // doco
    -1,            // keep state in global vars
    WmctrlMethods  // methods
};

PyMODINIT_FUNC PyInit_wmctrl(void) {
    return PyModule_Create(&wmctrlmodule);
}

int main(int argc, char *argv[]) {
    /* Add a built-in module, before Py_Initialize */
    PyImport_AppendInittab("wmctrl", PyInit_wmctrl);

    /* Pass argv[0] to the Python interpreter */
    Py_SetProgramName(argv[0]);

    /* Initialize the Python interpreter.  Required. */
    Py_Initialize();

    /* Optionally import the module; alternatively,
       import can be deferred until the embedded script
       imports it. */
    PyImport_ImportModule("wmctrl");

    PyMem_RawFree(argv[0]);
    return 0;
}
