#include<fstream.h>


int cmmdc(int a,int b)
{ if(!b) return a;
  if(a>b) return cmmdc(a-b,b);
  return cmmdc(a,b-a);


}






int main()
{int a,b,n;
 ifstream f("euclid2.in");
 f>>n;
 ofstream g("euclid2.out");
 for(int i=0;i<3;i++)
 {	 f>>a>>b;
	 g<<cmmdc(a,b)<<'\n';
 }
 f.close();
 g.close();
 return 0;
}
