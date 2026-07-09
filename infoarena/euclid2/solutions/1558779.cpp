#include <stdio.h>
int euclid ( int a , int b )
{
    if(!b)
        return a;
    return euclid(b, a%b);
}

int main()
{
    FILE *fin, *fout;
    fin=fopen("euclid2.in", "r");
    fout=fopen("euclid2.out", "w");
    int n , x , y  , rasp ;
    fscanf(fin, "%d", &n);
    for ( int i = 1 ; i <= n ; i++ )
    {
        fscanf(fin, "%d %d", &x, &y);
        rasp = euclid(x,y);
        fprintf(fout, "%d\n", rasp);
    }
    return 0 ;
}
