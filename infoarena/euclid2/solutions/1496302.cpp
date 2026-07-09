#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;
//ifstream fin("euclid2.in");
//ofstream gout("euclid2.out");


int euclid(int a,int b)
{
    if ( b ==0 ) return a;
    else return euclid(b,a%b);
}
int main()
{
    FILE *fin,*gout;
    fin = fopen("euclid2.in","r");
    gout = fopen("euclid2.out","w");

    int T,a,b;
    fscanf(fin,"%d",&T);
    for(int i=0;i<T;++i)
    {
        //fin>>a>>b;
        fscanf(fin,"%d%d",&a,&b);
        fprintf(gout,"%d\n",euclid(a,b));
    }
    return 0;
}
