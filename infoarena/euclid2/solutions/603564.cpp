#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
void citeste_vector(int& t,int a[])
{
	int i;
	f>>t;
	for(i=0;i<2*t;i++)
	f>>a[i];
}
void euclid(int t,int a[])
{
	int i,c[100000],j,r=1;
	
	for(j=0,i=0;j<t,i<2*t;j++,i=i+2)
	{
		r=a[i]%a[i+1];
		while(r!=0)
		{
		
		a[i]=a[i+1];
		a[i+1]=r;
		r=a[i]%a[i+1];
		}
        c[j]=a[i+1];	
		g<<c[j]<<" ";
        r=1;	
	}

}

int main()
{
	int t,a[200000];
	citeste_vector(t,a);
	euclid (t,a);
}	