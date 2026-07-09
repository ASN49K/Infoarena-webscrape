#include <stdio.h>

#define Nmax 1024
#define max(a, b) (a > b ? a : b)

int main()
{
    freopen("cmlsc.in","r", stdin);
    freopen("cmlsc.out","w", stdout);

    int x, y;

    scanf("%d", &x);
    scanf("%d", &y);
    if (x > Nmax || y > Nmax)
    {
        return 1;
    }

    int A[x], B[y], D[x + 1][y + 1];

    for (int i = 0; i < x; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < y; i++)
    {
        scanf("%d", &B[i]);
    }
    

    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            D[i][j] = 0;
        }
        
    }
    
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                D[i][j] = 1 + D[i - 1][j - 1];
            }
            else
            {
                D[i][j] = max(D[i - 1][j], D[i][j - 1]);
            }
            
        }
        
    }
    int len = D[x][y];
    int i = x;
    int j = y;
    int sir[len];

    while (i > 0 && j > 0)
    {
        if (A[i - 1] == B[j - 1])
        {
            sir[len - 1] = A[i - 1];
            len--;
            i--;
            j--;
        }
        else if (D[i - 1][j] > D[i][j - 1])
        {
            i--;
        }
        else 
            j--;
    }
    int n = D[x][y];
    printf("%i\n", n);
    for (int i = 0; i < n; i++)
        printf("%i ", sir[i]);
    printf("\n");
    return 0;
    
}