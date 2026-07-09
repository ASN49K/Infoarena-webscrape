#include <cstdio>

using namespace std;

int main()
{
    FILE*f=fopen("euclid2.in","r");
    FILE*g=fopen("euclid2.out","w");
    int n,a,b,r;
    fscanf(f,"%d",&n);
    while(n--)
    {
        fscanf(f,"%d%d",&a,&b);
        while(a!=b)
            if(a>b)
            {
                r=a/b;
                if(b*r==a)
                    r--;
                a=a-b*r;
            }
            else
            {
                r=b/a;
                if(a*r==b)
                    r--;
                b=b-a*r;
            }
        fprintf(g,"%d\n",a);
    }
    fclose(f);
    fclose(g);
    return 0;
}
