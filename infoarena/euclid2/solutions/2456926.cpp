/** Calcul CMMDC pentru T perechi de numere
**/

#include <bits/stdc++.h>

using namespace std;

FILE*fin=fopen("euclid.in","r");
ofstream fout("euclid.out");

int T,a,b;

int cmmdc(int x,int y)
{
    int r;
    if(x==0) return y;
    if(y==0) return x;
    if(x<y) swap(x,y);
    r=x%y;
    if(r==0) return y;
    else return cmmdc(y,r);
}

int main()
{
    int i;
    fscanf(fin,"%d",&T);
    for(i=1;i<=T;++i)
        {
            fscanf(fin,"%d%d",&a,&b);
        fout<<cmmdc(a,b)<<'\n';
        }
    return 0;
}
