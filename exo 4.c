#include <stdio.h>
int Max(int T[])
{
    int *p = T;
    int max = *p;
    for (int i = 1; i < 5; i++)
    {
        if (T[i] > max)
        {
            max = T[i];
        }
    }
    return max;
}
int main()
{
    int T[5] = {3, 7, 2, 9, 5};
    int max = Max(T);
    printf("The max is:%d", max);
    return 0;
}
