#include "Python.h"

int main()
{
	// Initialize the Python interpreter.
	Py_SetPythonHome(L"D:/Anaconda3");
	Py_Initialize();

	// Create some Python objects that will later be assigned values.
	PyObject  *pModule, *pDict, *pFunc_add, *pFunc_hello, *pArgs, *pValue, *pValue2;

	// Import the file as a Python module.
	pModule = PyImport_ImportModule("Sample");

	// Create a dictionary for the contents of the module.
	pDict = PyModule_GetDict(pModule);

	// Get the add method from the dictionary.
	pFunc_add = PyDict_GetItemString(pDict, "add");
	pFunc_hello = PyDict_GetItemString(pDict, "hello");

	// Create a Python tuple to hold the arguments to the method.
	pArgs = PyTuple_New(2);

	// Convert 2 to a Python integer.
	pValue = PyLong_FromLong(6);
	pValue2 = PyLong_FromLong(8);

	// Set the Python int as the first and second arguments to the method.
	PyTuple_SetItem(pArgs, 0, pValue);
	PyTuple_SetItem(pArgs, 1, pValue2);

	// Call the function with the arguments.
	PyObject_CallObject(pFunc_hello, NULL);
	PyObject* pResult = PyObject_CallObject(pFunc_add, pArgs);

	// Print a message if calling the method failed.
	if (pResult == NULL)
		printf("Calling the add method failed.\n");

	// Convert the result to a long from a Python object.
	long result = PyLong_AsLong(pResult);

	// Destroy the Python interpreter.
	Py_Finalize();

	// Print the result.
	printf("Calling Python to find the sum of 6 and 8.\n");
	printf("The result is %d.\n", result);
	return 0;
}