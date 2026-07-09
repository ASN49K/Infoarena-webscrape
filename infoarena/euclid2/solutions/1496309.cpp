#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

int euclid(int a,int b)
{
    if (b == 0) return a;
    return euclid(b, a%b);
}

int main()
{
    FILE *in,*out;
    in = fopen("euclid2.in","r");
    out = fopen("euclid2.out","w");

    int n,a,b;
    fscanf(in,"%d",&n);
    for (int i=0;i<n;i++)
    {
        fscanf(in,"%d %d",&a,&b);
	fprintf(out,"%d\n",euclid(a,b));
    }
    fclose(in); 
    fclose(out);
    return 0;
}
