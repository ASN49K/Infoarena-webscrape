#include <stdio.h>

using namespace std;

int max,l[1026],n,a[1026];

void citire()
{
    freopen("cmlsc.in","r",stdin);
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &a[i]);
    fclose(stdin);
}

void subsir()
{
    l[n-1]=1;
    max=1;
    for (int i=n-2; i>=0; i--)
    {
        for (int j=i+1; j<n; j++)
            if (a[i]<a[j])
                l[i]>?=l[j];
    l[i]++;
    if (l[i]>max)
        max=l[i];
    }
}

void afisare()
{
    for (int i=0; i<n; i++)
        if (l[i]==max)
        {
            printf("%d ",a[i]);
            max--;
        }
        else if (l[i]==0)
                break;
}

int main()
{
    freopen("cmlsc.out","w",stdout);
    citire();
    subsir();
    printf("%d\n",max);
    afisare();
    fclose(stdout);
    return 0;
}
