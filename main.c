#include <stdio.h>
#include "fibo.h"
#include "rabbit.h"

void question1()
{
    int n1 = fibo_recurente(15);
    int n2 = fibo_recursif(15);
    int n3 = fibo_explicite(15);
    printf("%d\t%d\t%d\n", n1, n2, n3);
}


int main()
{
    //question1();

    realistic_simulation();

    return 0;
}