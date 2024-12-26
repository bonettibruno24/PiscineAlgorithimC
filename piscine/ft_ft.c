#include <stdio.h>
#define VALOR_DE_PI 3.1415

//make a pointer 42
void ft_ft(int *mbr)
{
    printf("%p", &mbr);
    *mbr = 42;
}

int main(void)
{
    int a;
    int *pointer;

    printf("%p", &a);
    pointer = &a;
    ft_ft(pointer);
    printf("%d\n", a);
}
