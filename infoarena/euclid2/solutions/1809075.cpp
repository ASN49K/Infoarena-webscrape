#include <cstdio>
#include <fstream>

#define minim(a,b) ((a<b) ? a : b)
#define maxim(a,b) ((a>b) ? a : b)

using namespace std;

int n,a[100],b[100],c[50];

void R(char nume_fis[20])
{
    fstream f(nume_fis,ios::in);
    f >> n;
    for(int i=0;i<n;i++)
        f >> a[i] >> b[i];
}

int cmmdc(int m,int n)
{
    if(n==0)
        return m;
    if(m>n)
        return cmmdc(m-n,n);
    return cmmdc(m,n-m);

}

int main()
{
    R("euclid2.in");
    for(int i=0;i<n;i++)
    {
        c[i] = cmmdc(a[i],b[i]);
    }
    FILE *f=fopen("euclid2.out","w");
    for(int i=0;i<n;i++)
        fprintf(f,"%i\n",c[i]);
    return 0;
}
