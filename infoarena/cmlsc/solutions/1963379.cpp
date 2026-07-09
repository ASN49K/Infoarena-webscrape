#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{   int a[30], b[30], C[30][30], m, n,i,j,t;

     ifstream f; ofstream g;
    f.open("cmlsc.in"); g.open("cmlsc.out");
    f>>m>>n;

    for(i=1;i<=m;i++)
    f>>a[i];

    for(i=1;i<=n;i++)
    f>>b[i];

    for(i=0;i<=m;i++)
    C[i][0]=0;

    for(i=0;i<=n;i++)
    C[0][i]=0;

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++){

        if (a[i]==b[j]){

            C[i][j]=C[i-1][j-1]+1;}
        else{

            C[i][j]=max(C[i-1][j], C[i][j-1]);}
       }

    }

    t=0;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++){

        if (C[i][j]>t){
            b[t]=a[i];
            t++;

    }}}


    g<<t<<"\n";
    for(i=0;i<t;i++)
    {
        g<<b[i]<<" ";
    }

    f.close();g.close();

    return 0;
}

