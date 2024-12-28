  void ft_swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int a;
    int b;
    int *pa;
    int *pb;

    a = 42;
    b = 24;
    pa = &a;
    pb = &b;

    printf("Before swap: a = %d, b = %d\n", a, b);
    ft_swap(pa, pb);
    printf("After swap: a = %d, b = %d\n", a, b);
    return 0;
  }