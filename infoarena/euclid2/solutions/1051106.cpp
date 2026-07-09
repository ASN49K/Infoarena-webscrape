#include <iostream>
#include <stdio.h>
using namespace std;
int euclid(int a,int b)
{
    int r;
     while(b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        return a;
}
int main()
{
    FILE *in, *out;
    in = fopen("euclid2.in","r");
    out = fopen("euclid2.out", "w");
    int T,i,a, b;
    fscanf(in, "%d", &T);
    for(i=1; i<= T; i++)
    {
        fscanf(in, "%d", &a);
        fscanf(in, "%d", &b);
        fprintf(out,"%d\n", euclid(a,b));
    }
    return 0;
}
