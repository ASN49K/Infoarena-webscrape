#include<fstream.h>


int cmmdc(int a,int b)
{if(a==0) return b;
  else

   if(b==0) return a;
 else
 if(a>b)
	return cmmdc(a%b,b);
 else
	if(a<b)
		return cmmdc(a,b%a);
	else
    	return b;


}


int main()
{int a,b,n;
 ifstream f("euclid2.in");
 f>>n;
 ofstream g("euclid2.out");
 for(int i=0;i<n;i++)
 {	 f>>a>>b;
	 g<<cmmdc(a,b)<<'\n';
 }
 f.close();
 g.close();
 return 0;
}
