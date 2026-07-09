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
    fopen("euclid2.in","r",stdin);
    fopen("euclid2.out","w",stdout);

    int n,a,b;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
	printf("%d\n",euclid(a,b));
    }
    
    return 0;
}
