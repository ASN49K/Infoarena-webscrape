#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 100005

using namespace std;

int a[N],l[N],n,poz,lmax;

void prelucrare()
{
    int maxim = 0;

    l[n - 1] = 1;

    for(int i = n - 2 ; i >= 0 ; --i)
    {
        maxim = 0;

        for(int j = i + 1 ; j < n ; ++j)
        {
            if(a[j] > a[i] && l[j] > maxim)
            {
                maxim = l[j];
            }
        }

        l[i] = maxim + 1;

        if(lmax < l[i])
        {
            lmax = l[i];

            poz = i;
        }
    }
}

void afisare()
{
    printf("%d\n",lmax);

    bool ok;

    while(l[poz])
    {
        printf("%d ",a[poz]);

        ok = false;

        for(int i = poz + 1; i < n ; ++i)
        {
            if(l[i] == l[poz] - 1 && a[i] > a[poz])
            {
                poz = i;

                ok = true;

                break;
            }
        }
        if(!ok)
        {
            break;
        }
    }
}

void citire()
{
    scanf("%d\n",&n);

    for(int i = 0 ; i < n ; ++i)
    {
        scanf("%d ",&a[i]);
    }

    prelucrare();

    afisare();
}

int main()
{
    freopen("scmax.in","r",stdin);
    freopen("scmax.out","w",stdout);

    citire();

    return 0;
}
