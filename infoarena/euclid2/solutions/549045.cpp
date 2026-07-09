#include<stdio.h>
FILE *in,*out;
int a,b;

int gcd(int u,int v)
{
    if(u==v)
        return u;
    if(!u)
        return v;
    if(!v)
        return u;
    if(!(u & 1))
    {
        if(!(v & 1))
            return (2*gcd(u>>1,v>>1));
        else
            return gcd(u>>1,v);
    }
    else
        if(!(v & 1))
            return gcd(u,v>>1);
        else
            if(u>=v)
                return gcd((u-v)>>1,v);
            else
                return gcd((v-u)>>1,u);

}

int main()
{
    in=fopen("euclid2.in","rt");
    out=fopen("euclid2.out","wt");
    int n;
    fscanf(in,"%d",&n);
    for(int i=1;i<=n;i++)
    {
        fscanf(in,"%d %d",&a,&b);
        fprintf(out,"%d\n",gcd(a,b));
    }

    return 0;
}
