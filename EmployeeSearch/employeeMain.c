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
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

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

    // Example found using phone search
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-555-2134");
    if (matchPtr != NULL)
        printf("Employee phone 909-555-2134 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee phone 909-555-2134 is NOT found in the record\n");

    // Example not found using phone search
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "098-765-4321");
    if (matchPtr != NULL)
        printf("Employee phone 098-765-4321 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee phone 098-765-4321 is NOT found in the record\n");

    // Example found using salary search
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.32);
    if (matchPtr != NULL)
        printf("Employee salary 8.32 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee salary 8.32 is NOT found in the record\n");

    // Example not found using salary search
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 33.1);
    if (matchPtr != NULL)
        printf("Employee salary 33.1 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee salary 33.1 is NOT found in the record\n");

    return EXIT_SUCCESS;
}