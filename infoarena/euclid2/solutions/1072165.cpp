#include<fstream>
using namespace std;
int euclid(int a,int b)
{if(a==b)return a;
else
	if(a>b)
		return euclid(a-b,b);
	else
		return euclid(a,b-a);
}


int main()
{int a,b,t;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>t;
while(t!=0)
	{f>>a>>b;
		t--;
		g<<euclid(a,b)<<endl;
}

}