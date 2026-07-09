// Cel mai lung sir comun.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
constexpr auto NMAX = 1024;

int M, N, D[NMAX][NMAX], A[NMAX], B[NMAX], sir[NMAX], k;

int main(void)
{
    int i, j ;
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    
   
    scanf("%d %d", &M, &N);
    for (i = 1; i <= M; ++i)
        scanf("%d", &A[i]);
    for (j = 1; j <= N; ++j)
        scanf("%d", &B[j]);


    for (i = 1; i <= M; ++i)
        for (j = 1; j <= N; ++j)
            if (A[i] == B[j])
                D[i][j] = 1 + D[i - 1][j - 1];
            else D[i][j] = ((D[i - 1][j] > D[i][j - 1]) ? D[i - 1][j] : D[i][j - 1]);
    
    
    for (i = M, j = N; i; )
    {
        if (A[i]==B[j])
        {
            sir[++k] = A[i];
            --i; --j;
        }
        else if (D[i - 1][j] > D[i][j-1])
            --i;
        else --j;
    }
    printf("%d\n", k);
    for (i = k; i; --i)
        printf("%d ", sir[i]);
    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
