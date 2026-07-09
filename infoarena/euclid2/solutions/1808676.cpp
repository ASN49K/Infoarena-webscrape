#include <cstdio>
#include <fstream>

#define minim(a,b) ((a<b) ? a : b)

using namespace std;

int n,a[100],b[100],c[50];

void R(char nume_fis[20])
{
    fstream f(nume_fis,ios::in);
    f >> n;
    for(int i=0;i<n;i++)
        f >> a[i] >> b[i];
}

void Euclid2(int x)
{
    int z=minim(a[x],b[x]);
    for(int i=1;i<=z;i++)
    {
        if((a[x]%i==0)&&(b[x]%i==0))
            c[x]=i;
    }
}

int main()
{
    R("euclid2.in");
    for(int i=0;i<n;i++)
    {
        Euclid2(i);
    }
    FILE *f=fopen("euclid.out","w");
    for(int i=0;i<n;i++)
        fprintf(f,"%i\n",c[i]);
    return 0;
}
