
#include <stdio.h>
using namespace std;

void Out(int x[], int n);
void Try(int i, int n, int x[], int a[], int b[], int c[]);
int count = 0;
int main()
{
    int n;
    printf("nhap n ");
    scanf("%d",&n);
    int a[100], b[100], c[100], x[100];
    for (int i = 1; i <= n; i++)
    {
        a[i] = 1;
    }
    for (int i = 2; i <= 2 * n; i++)
    {
        b[i] = 1;
    }
    for (int i = 1 - n; i <= n - 1; i++)
    {
        c[i] = 1;
    }
    
    Try(1, n, x, a, b, c);
    return 0;
}

void Out(int x[], int n)
{
    count ++;
    printf("%d : ",count);
    for (int i = 1; i <= n; i++)
    {
        printf("%d", x[i]);
    }
    printf("\n");
}

void Try(int i, int n, int x[], int a[], int b[], int c[])
{
    for (int j = 1; j <= n; j++)
    {
        if (a[j] == 1 && b[i + j] == 1 && c[i - j] == 1)
        {
            x[i] = j;
            a[j] = 0;
            b[i+j] = 0;
            c[i-j] = 0;
            if (i == n) Out(x, n);
            else Try(i + 1, n, x, a, b, c);
            a[j] = 1;
            b[i + j] = 1;
            c[i - j] = 1;
        }
    }
}

