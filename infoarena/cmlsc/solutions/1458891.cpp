#include <iostream>
#include <fstream>
#define fin "cmlsc.in"
#define fou "cmlsc.out"
#define nmax 1026
using namespace std;
int sol[nmax][nmax],a[nmax],b[nmax],la,lb;
int fini[nmax];
int nrelem;

int maxim(int a,int b)
{
    if(a>b) return a;
    else return b;
}

int main()
{
    int i,j,nrmax;
    ifstream t1(fin);
    ofstream t2(fou);
    t1>>la>>lb;
    for(i=1;i<=la;i++) t1>>a[i];
    for(i=1;i<=lb;i++) t1>>b[i];

    for(i=1;i<=la;i++)
        for(j=1;j<=lb;j++)
            if(a[i]==b[j]) sol[i][j]=sol[i-1][j-1]+1;
            else sol[i][j]=maxim(sol[i-1][j],sol[i][j-1]);
    nrmax=sol[la][lb];
    t2<<nrmax<<'\n';
    for(i=la;i>=1 && nrmax>0 ;i--)
        for(j=lb;j>=1 && nrmax>0; j--)
            if(a[i]==b[j]) { nrelem++; fini[nrelem]=a[i]; }
    for(i=nrelem;i>=1;i--) t2<<fini[i]<<' ';
    t1.close();
    t2.close();
    return 0;
}
