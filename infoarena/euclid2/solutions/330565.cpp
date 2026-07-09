#include<fstream>
#include<cstdio>

using namespace std;

//ifstream in("euclid2.in");
//ofstream out("euclid2.out");

int cmmdc(int a,int b)
{
	int r;
	while(b)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int t,a,b;
	//in>>t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		//in>>a>>b;
		scanf("%d%d",&a,&b);
		//out<<cmmdc(a,b)<<endl;
		printf("%d\n",cmmdc(a,b));
	}
	return 0;
}
