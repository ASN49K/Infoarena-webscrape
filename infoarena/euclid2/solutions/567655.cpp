#include<fstream>
using namespace std;
int divab(int a,int b)
{
	int r;
	if(b==0) 
		return a;
	else 
	{
	r=a%b;
	a=b;
	b=r;
	}
	if(b==0) return a;
	return divab(a,b);
	

}




int main()
{
	int t,i,a,b;
	ifstream f("euclid2.in");
	f>>t;
	ofstream g("euclid2.out");
	for(i=0;i<t;i++)
		{
		f>>a>>b;
		g<<divab(a,b)<<endl;
		}
}
	
	