#include <string.h>
#include "employee.h"

PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int tableSize, long targetNumber) {
    const PtrToConstEmployee endPtr = ptr + tableSize;

    for (; ptr < endPtr; ptr++)     // Search until end of table
    {
        if (ptr->number == targetNumber)   // Check if it equals the Employee number
            return (PtrToEmployee) ptr;     // Return location of the number to callee
    }
    return NULL;    // This will only happen if no Employee number matches in loop
}

// Same functionality as above function but compares strings
PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char *targetName) {
    const PtrToConstEmployee endPtr = ptr + tableSize;

    for (; ptr < endPtr; ptr++) 
    {
        if (strcmp(ptr->name, targetName) == 0)
            return (PtrToEmployee) ptr;
    }
    return NULL;
}