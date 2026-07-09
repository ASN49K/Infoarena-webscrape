#include <cstdlib>
#include <iostream>
#define MAX 1100
using namespace std;
int a[MAX],b[MAX],c[MAX];


int main(int argc, char *argv[])
{
    FILE *fin=fopen("cmlsc.in","r"),
         *fout=fopen("cmlsc.out","w");
    
    int m,n;
    fscanf(fin,"%i %i",&m,&n);
    for(int i=0;i<m;i++) fscanf(fin,"%d",&a[i]);
    for(int i=0;i<n;i++) fscanf(fin,"%i",&b[i]);
    int k=0;
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
       if(a[i]==b[j]) c[k++]=b[j];
    fprintf(fout,"%i\n",k);
    for(int i=0;i<k;i++) fprintf(fout,"%i ",c[i]);   
    fclose(fin);
    fclose(fout);                
    return EXIT_SUCCESS;
}
