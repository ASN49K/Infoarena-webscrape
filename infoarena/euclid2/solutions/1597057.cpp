#include <stdio.h>


using namespace std;

int cmmdc(int k,int l)
{int r;
    if(l==0)return k;
    else {while(l!=0){r=k%l;k=l;l=r;}
    return k;}
}
int main()
{int a,b,t,i;
FILE *fin,*fout;
fin=fopen("euclid2.in","r");
fout=fopen("euclid2.out","w");
fscanf(fin,"%d",&t);
for(i=1;i<=t;i++){fscanf(fin,"%d %d",&a,&b);
fprintf(fout,"%d\n",cmmdc(a,b));}
    return 0;
}




