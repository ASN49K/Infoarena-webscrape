#include <stdio.h>
using namespace std;
int n,i,a,b,cat,rest;
int main()
{FILE *fin=fopen("euclid2.in","r");
 FILE *fout=fopen("euclid2.out","w");
 fscanf(fin,"%d",&n);
 for(i=1;i<=n;i++)
  {fscanf(fin,"%d %d",&a,&b);
   rest=1;
   while(rest!=0)
    {cat=a/b;
     rest=a%b;
     a=b;
     if(rest!=0) b=rest;
    }
   fprintf(fout,"%d\n",b);
  }
 fclose(fin);fclose(fout);
 return 0;
}
