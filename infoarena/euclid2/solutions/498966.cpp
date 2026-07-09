#include<fstream.h>
#include<string.h>
int euclid(int a,int b)
{while(a!=b)
 if(a>b)a=a-b;
   else b=b-a;
 return a;
}
int main()
{ifstream f("euclid2.in");
 ofstream g("euclid2.out");
 int t,a,b,i;
 f>>t;
for(i=1;i<=t;i++)
 {f>>a>>b;
 g<<euclid(a,b);
}
return 0;
}