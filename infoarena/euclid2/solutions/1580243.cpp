#include <iostream>
#include <fstream>



using namespace std;
FILE *f = fopen("euclid2.in" ,"r");
FILE *g = fopen("euclid2.out","w");


int cmmmdc(int a, int b)
{
    while ( a!=b )
    {
        if ( a>b ) a-=b;
        else b-=a;
    }
    return a;
}

int N,l,L;
int main()
{
    fscanf(f,"%d",&N);
    for ( int i=1 ; i<=N ; i++ )
    {
        fscanf(f,"%d %d",&l,&L);
        fprintf(g,"%d\n",cmmmdc(l,L));
    }
}
