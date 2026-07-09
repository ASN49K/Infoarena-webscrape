#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int vec[100001];
int primul[100001];
int poz[100001];
int n, m;

int cautare(int i, int s, int x)
{
    int mij;
    while(i <= s)
    {
        mij = i + (s - i) / 2;
        if(x < vec[primul[mij]])
            i = mij + 1;
        else
            s = mij - 1;
    }
    return i;
}

void subsir()
{
    vec[0] = 1234567890;
    for(int i = n; i > 0; i--)
    { 
        poz[i] = 0;
        int k = cautare(1, m, vec[i]);
        if(k > m)
        {
            poz[i] = primul[k - 1];
            m = k;
            primul[k] = i;
        }
        else
        {
            poz[i] = primul[k - 1];
            if(vec[primul[k]] < vec[i])
                primul[k] = i;
        }
    }
}

int main()
{
    FILE *f = fopen("scmax.in", "r");
    FILE *g = fopen("scmax.out", "w");
    fscanf(f, "%d\n", &n);
    for(int i = 1; i <= n; i++)
        fscanf(f, "%d ", &vec[i]);
    subsir();
    fprintf(g, "%d\n", m);
    for(int i = primul[m]; i > 0; i = poz[i])
        fprintf(g, "%d ", vec[i]);
    fprintf(g, "\n");

    fclose(f);
    fclose(g);

    return 0;
}
