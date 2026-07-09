#include <cstdio>

using namespace std;
int cmmdc (int a,int b){
    int r;
    while (b>0){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    FILE *fin=fopen ("euclid2.in","r");
    FILE *fout=fopen ("euclid2.out","w");
    int t,a,b,i;
    fscanf (fin,"%d",&t);
    for (i=1;i<=t;i++){
        fscanf (fin,"%d%d",&a,&b);
        fprintf (fout,"%d\n",cmmdc(a,b));
    }
    return 0;
}
