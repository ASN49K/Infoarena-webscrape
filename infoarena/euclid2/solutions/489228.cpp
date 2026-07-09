#include<fstream>
using namespace std;
int n,c[16][16],i,j;
int cmmdc(int a,int b)
{
	 int rest;
	 for(;;)
	 {
		  rest=a%b;
		  a=b;
		  if(rest==0)
			  return b;
		  b=rest;
	 }
	 return 0;
}
int main()
{
	 ifstream f("euclid2.in");
	 ofstream g("euclid2.out");
	 int n;
	 f>>n;
	 int m=2;
	 for(i=1;i<=n;i++)
		 for(j=1;j<=m;j++)
			 f>>c[i][j];
		 for(i=1;i<=n;i++)
		 {
				g<<cmmdc(c[i][1],c[i][2])<<" ";
					  g<<"\n";
		 }
		 f.close();
		 g.close();
		 return 0;
}
