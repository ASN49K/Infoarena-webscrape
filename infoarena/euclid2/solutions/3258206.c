#include <stdio.h>
#include <stdlib.h>

int cmmd (int a,int b){

    if (a>b) {
        int cnt=a;
        a=b;
        b=cnt;
    }
     if (b%a==0){
            return a;
    }
        for (int d=a/2;d>0;d--){
            if (a%d==0 && b%d==0){
                return d;
            }
        }
    }
int main()
{
    int n,i,a,b;
    FILE *r,*w;
    r= fopen("euclid2.in","r");
    w= fopen("euclid2.out","w");
    fscanf(r,"%d",&n);

    for (i=0;i<n;i++){
        fscanf (r,"%d%d",&a,&b);
        fprintf (w, "%d\n",cmmd(a,b));
    }
    return 0;
}
