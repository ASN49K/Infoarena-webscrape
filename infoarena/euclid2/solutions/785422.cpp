#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    FILE * f,* g;
    f=fopen("euclid2.in","r");
    g=fopen("euclid2.out","w");

    fscanf(f,"%d",&n);
    for(int i=0;i<n;i++){
        int a,b;
        fscanf(f,"%d %d",&a,&b);
        while (b!=0){
            int r=a%b;
            a=b;
            b=r;
        }
        fprintf(g,"%d\n",a);
    }
    return 0;
}
