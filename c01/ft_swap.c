  void ft_swap(int *a, int *b)
{
    int temp;
    temp = *a;
    printf("temp = %d\n",temp);
    *a = *b;
    *b = temp;
    printf("temp = %d\n", *a);
}

int main(void)
{
    int a, b;
    int *pa, *pb;
    a = 42;
    b = 24;
    pa = &a;
    pb = &b;

    printf("Before swap: a = %d, b = %d\n", a, b);
    ft_swap(pa, pb);
    printf("After swap: a = %d, b = %d\n", a, b);
    return 0;
  }