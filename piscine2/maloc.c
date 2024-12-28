#include <stdio.h>
#include <stdlib.h>


int main()
{
    int* ptr = (int*) malloc(5* sizeof (int));
    ptr = 23;
    printf("%p\n", ptr);

    // int a, b;

    // printf("Enter a number: ");
    // scanf("%d", &a);
    // printf("Enter a second number: ");
    // scanf("%d", &b);
    // printf("A: %d \t B : %d" , 
    // a, b);


    printf("Tamanho de unsigned long: %zu bytes\n", sizeof(unsigned long int));
    
    return 0;

}