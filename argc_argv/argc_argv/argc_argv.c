#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main(int argc, char *argv[])
{
    printf("start \n");
    //printf("%d %s %s %s ", argc, argv[0], argv[1], argv[2]);

    printf("%d+%d=%d\n",atoi(argv[1]), atoi(argv[2]), atoi(argv[1]) + atoi(argv[2]));
    
    printf("\nend \n");
    getchar();
    printf("program was done \n");



    return 0;
}
