#include <stdio.h>
#define VALOR_DE_PI 3.1415

//make a pointer 42
void ft_ft(int *mbr)
{
    *mbr = 42;
}

int main(void)
{
    int a;
    int *pointer;

    printf("%p", &a); //%p func to print andress 
    pointer = &a;
    ft_ft(pointer);
    printf("%d\n", a);
}
