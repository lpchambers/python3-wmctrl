#include <Python.h>
#include <X11/Xlib.h>

static int get_x_display(char *display_name, Display *disp) {
    if (! (disp = XOpenDisplay(display_name))) {
        // Set the error vars
        return -1;
    }
    return 0;
}

static PyObject *wmctrl_list_windows(PyObject *self, PyObject *args) {
    Display *disp;

    if (get_x_display(NULL, disp) != 0) {
        return NULL;
    }

    return PyLong_FromLong(3);
}

static PyMethodDef WmctrlMethods[] = {
    {"list_windows", wmctrl_list_windows, METH_NOARGS,
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
