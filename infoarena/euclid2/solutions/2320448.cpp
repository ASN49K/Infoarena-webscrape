#include <bits/stdc++.h>

int euclid(int a,int b){
    int r;
    while(a%b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return b;
}

int main()
{
    int i,n,a,b;
    FILE*fi,*fo;
    fi=fopen("euclid2.in","r");
    fo=fopen("euclid2.out","w");
    fscanf(fi,"%d",&n);
    for(i=0;i<n;i++){
        fscanf(fi,"%d%d",&a,&b);
        fprintf(fo,"%d\n",euclid(a,b));
    }
    fclose(fi);
    fclose(fo);
    return 0;
}
