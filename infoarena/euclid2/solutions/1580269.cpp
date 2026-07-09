#include <iostream>
#include <fstream>



using namespace std;
FILE *f = fopen("euclid2.in" ,"r");
FILE *g = fopen("euclid2.out","w");


int cmmmdc(int a, int b)
{
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
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
