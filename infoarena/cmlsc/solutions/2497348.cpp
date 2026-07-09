#include <stdio.h>
#include <iomanip>
#include <iostream>
#define n 1024

using namespace std;

int a[n], b[n], sol[n][n], sir[n], na, nb, ns;

void citire()
{
    freopen("cmlsc.in", "r", stdin);
    scanf("%d %d", &na, &nb);

    for(int i = 1; i <= na; i++)
        scanf("%d", &a[i]);

    for(int i = 1; i <= nb; i++)
        scanf("%d", &b[i]);

}

void addMatrice()
{

    for(int i = 1; i <= na; i++)
        for(int j = 1; j <= nb; j++)
            (a[i]==a[j])?
                sol[i][j] = 1 + sol[i-1][j-1]:
                sol[i][j] = max(sol[i-1][j], sol[i][j-1]);


}

void generareSolutie()
{

    for(int i=na, j=nb;i;)
        if(a[i]==b[j])
            sir[++ns] = a[i], --i, --j;
        else if(sol[i-1][j] > sol[i][j-1])
            i--;
        else
            j--;

}

void afis()
{

    freopen("cmlsc.out", "w", stdout);

    printf("%d\n", ns);

    for(int i = ns; i; --i)
        printf("%d ", sir[i]);

}

int main()
{
    citire();
    addMatrice();
    generareSolutie();
    afis();
    return 0;
}
