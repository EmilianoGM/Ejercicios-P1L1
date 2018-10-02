#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "Biblioteca.h"
#include "ArrayEmployees.h"

int initEmployees(Employee* list, int len)
{
    if(list != NULL && len > 0)
    {
        int index;
        for(index = 0; index < len; index ++)
        {
            list[index].isEmpty = TRUE;
        }
        return 0;
    }
    return -1;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    if(list != NULL && len > 0)
    {
        int index;
        for(index = 0; index < len; index ++)
        {
            if(list[index].isEmpty == TRUE)
            {
                list[index].id = id;
                strcpy(list[index].name, name);
                strcpy(list[index].lastName, lastName);
                list[index].salary = salary;
                list[index].sector = sector;
                return 0;
            }
        }
    }
    return -1;
}

int findEmployeeById(Employee* list, int len,int id)
{
    if(list != NULL && len > 0)
    {
        int index;
        for(index = 0; index < len; index ++)
        {
            if(list[index].id == id)
            {
                return index;
            }
        }
    }
    return -1;
}

int removeEmployee(Employee* list, int len, int id)
{
    if(list != NULL && len > 0)
    {
        int index = findEmployeeById(list, len, id);
        if(index != -1)
        {
            if(list[index].id == id)
            {
                list[index].isEmpty = FALSE;
                return 0;
            }
        }
    }
    return -1;
}
