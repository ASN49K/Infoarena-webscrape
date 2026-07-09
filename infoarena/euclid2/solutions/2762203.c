#include <stdio.h>
#include <stdlib.h>
int euclid(int a,int b)
{   while(b != 0){
    int r = a%b;
    a = b;
    b = r;
}
return a;

}
int main()
{   int n,x,y;
    FILE* pf = fopen("euclid2.in","r");
    FILE* pf1 = fopen("euclid2.out","w");
    fscanf(pf,"%d",&n);
    while(n)
    {   fscanf(pf,"%d%d",&x,&y);
        n--;
        fprintf(pf1,"%d\n",euclid(x,y));

    }

    return 0;
}
