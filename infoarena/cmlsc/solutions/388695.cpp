#include<cstdio>
#include<vector>
using namespace std;
vector<int>a,b;
vector< vector<int> > d;
int A,B,C,D,E;
void read(), solve();
int main()
{
	read();
	solve();
	return 0;
}
void read()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&A,&B);
	a.push_back(0);for(C=1;C<=A;C++){scanf("%d",&D);a.push_back(D);}
	b.push_back(0);for(C=1;C<=B;C++){scanf("%d",&D);b.push_back(D);}
}
void solve()
{
	vector<int> c;
	for(C=0;C<=B;C++)c.push_back(0);
	for(C=0;C<=A;C++)d.push_back(c);
	for(C=1;C<=A;C++)
	{
		for(D=1;D<=B;D++)
		{
			if(a[C]==b[D])d[C][D]=d[C-1][D-1]+1; 
			else d[C][D]=d[C][D-1]>d[C-1][D]?d[C][D-1]:d[C-1][D];
		}		
	}
	printf("%d\n",d[A][B]);
	c.resize(0);
	for(;d[A][B];)
	{
		if(a[A]==b[B]){c.push_back(a[A]);A--;B--;}
		else if(d[A][B]==d[A-1][B])A--;
		else B--;
	}
	for(;c.size();){printf("%d ",c.back());c.pop_back();}
}

