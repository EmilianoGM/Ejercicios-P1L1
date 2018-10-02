#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    /*char array[13];
    fflush(stdin);
    fgets(array, 13, stdin);
    */
    int e = 8;
    int n = isdigit(e);
    printf("%d", n);
    return 0;
}
