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
    fopen("euclid2.in","r");
    fopen("euclid2.out","w");

    int n,a,b;
    fscanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        fscanf("%d %d",&a,&b);
	fprintf("%d\n",euclid(a,b));
    }
    
    return 0;
}
