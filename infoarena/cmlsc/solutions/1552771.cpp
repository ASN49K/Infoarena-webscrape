#include <cstdio>

using namespace std;

int s1[100000];
int s2[100000];
int x[100000];
int afisaj[100000];

int n;
int lungime = 0;

void citire()
{
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }
}

void construiesteSiruri()
{
    int nr = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(s1[j] == 0 || s1[j] >= x[i])
            {
                s1[j] = x[i];
                s2[i] = j;

                if(j > lungime)
                {
                    lungime = j;
                }

                break;
            }
        }
    }
}

void afisare()
{
    printf("%d\n", lungime + 1);

    int nr = lungime + 1;

    int nrx = 0;

    for(int i = n - 1; i >= 0; i--)
    {
        if(s2[i] + 1 == nr)
        {
            afisaj[nrx] = x[i];
            nrx++;
            nr--;
        }
    }

    for(int i = nrx - 1; i >= 0; i--)
    {
        printf("%d ", afisaj[i]);
    }
}

int main()
{
    freopen("scmax.in", "r", stdin);
    freopen("scmax.out", "w", stdout);

    citire();
    construiesteSiruri();
    afisare();


    return 0;
}
