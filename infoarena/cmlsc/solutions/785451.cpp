#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
   FILE *f, *g;
   int c1[1025],c2[1025];
   f=fopen("cmlsc.in","r");
   g=fopen("cmlsc.out","w");

   int m,n;
   fscanf(f,"%d %d",&m, &n);
   int a[1024],b[1024];
   for (int i=0;i<m;i++){
        fscanf(f,"%d",&a[i]);
        c1[i]=0;
   }
   cout<<endl;
   for (int i=0;i<n;i++){
        fscanf(f,"%d",&b[i]);
   }

   int r[1025],rn=0;

   for (int i=1;i<=n;i++){
        for (int p=0;p<=m;p++){
        c2[p]=c1[p];
        }
    for(int j=1;j<=m;j++){
        if (a[j-1]==b[i-1]){
            c1[j]=c2[j-1]+1;
            r[rn++]=a[j-1];

        }
        else{
            if(c2[j]>c1[j-1]) c1[j]=c2[j];
            else c1[j]=c1[j-1];
        }
    }
   }
   int k=c1[m];
   fprintf(g,"%d\n",k);
   for(int i=0;i<rn;i++)
   fprintf(g,"%d ",r[i]);
   fclose(f);
   fclose(g);
    return 0;

}
