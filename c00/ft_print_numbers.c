#include <stdlib.h>

void ft_print_numbers(void)
{
    char *numbers = "0123456789";
    int i = 0;
    while (numbers[i])
    {
        write(1, &numbers[i], 1);
        i++;
    }
}

int main()
{
    ft_print_numbers();
    return 0;
}