// gcc employeeMain.c employeeTable.c employeeOne.c
// gcc employeeMain.c employeeTable.c employeeTwo.c

#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void) {
    // defined in employeeOne.c or employeeTwo.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char * phoneToFind);


    // defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr; // Declaration
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

    // Example not found
    if (matchPtr != NULL)
        printf("Employee ID 1045 is in record %d %d\n", matchPtr - EmployeeTable, matchPtr->number);
    else
        printf("Employee ID 1045 is NOT found in the record\n");

    // Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");

    // Example of employee phone found using search by phone
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-555-1235");
    if (matchPtr != NULL)
        printf("Employee phone 909-555-1235 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee phone 909-555-1235 is NOT found in the record\n");

    // Example of employee phone found using search by phone
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "123-456-7890");
    if (matchPtr != NULL)
        printf("Employee phone 123-456-7890 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee phone 123-456-7890 is NOT found in the record\n");

    return EXIT_SUCCESS;
}