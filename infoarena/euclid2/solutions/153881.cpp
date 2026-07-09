#include<fstream.h>


int cmmdc(int a,int b)
{if(a<b)
	return cmmdc(a,b-a);
  else
	if(a>b)
		return cmmdc(a-b,b);
	else
		return a;
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
