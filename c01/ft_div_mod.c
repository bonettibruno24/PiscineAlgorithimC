void ft_div_mod(int a, int b, int *div, int *mod)
{
    *div = a / b;
    *mod = a % b;
}

int main(void)
{
    int a, b;
    int div, mod;
    a = 10;
    b = 4;

    ft_div_mod(a, b, &div, &mod);
    printf("a = %d, b = %d\n", a, b);
    printf("div = %d, mod = %d\n", div, mod);
    return 0;
}