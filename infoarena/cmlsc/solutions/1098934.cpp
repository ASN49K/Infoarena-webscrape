#include <iostream>
#include <stdio.h>

using namespace std;

FILE *f1=freopen("scmax.in", "r", stdin);
FILE *f2=freopen("scmax.out", "w", stdout);
int n, a[100001], l[100001], poz;

void cit()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &a[i]);
}

int lmaxim()
{
    for (int i=n-1; i>=0; i--)
    {
        l[i]=1;
        for (int j=i+1; j<n; j++)
            if (a[i]<a[j] && l[i]<l[j]+1)
                l[i]=l[j]+1;
    }
    int maxi=0;
    for (int i=0; i<n; i++)
        if (l[i]>maxi)
        {
            maxi=l[i];
            poz=i;
        }
    return maxi;
}

void afdrum()
{
    for (int i=poz; i<n; i++)
    {
        printf("%d ", a[i]);
        int aux=l[i];
        while(aux!=l[i+1]+1)
            i++;
    }
}

int main()
{
    cit();
    printf("%d\n", lmaxim());
    afdrum();
    return 0;
}
