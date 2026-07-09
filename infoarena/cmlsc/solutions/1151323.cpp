#include<fstream>
#include<vector>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int main()
{
	int n,m,i,j;
	in>>n>>m;
	vector<int> a,b,c;
	vector< vector <int> > s;
	s.resize(n+1);
	a.resize(n);
	b.resize(m);
	for(i=0;i<n;i++) in>>a.at(i);
	for(i=0;i<m;i++) in>>b.at(i);
	s.at(0).resize(m+1);
	for(i=1;i<=n;i++) 
	{
		s.at(i).resize(m+1);
		for(j=1;j<=m;j++) 
		{
			s.at(i).at(j)=((s.at(i-1).at(j)>s.at(i).at(j-1))?s.at(i-1).at(j):s.at(i).at(j-1))+(a.at(i-1)==b.at(j-1));
			if(s.at(i).at(j)-s.at(i-1).at(j)>1) s.at(i).at(j)=s.at(i-1).at(j)+1;
			if(s.at(i).at(j)-s.at(i).at(j-1)>1) s.at(i).at(j)=s.at(i).at(j-1)+1;
		}
	}
	out<<s.at(n).at(m)<<'\n';
	c.resize(s.at(n).at(m));
	for(i=0;i<c.size();)
	{
		if(n>0) 
		{
			if(s.at(n-1).at(m)+1==s.at(n).at(m)) 
			{
				n--;
				c.at(i)=a.at(n);
				i++;
			}
			else if(s.at(n-1).at(m)==s.at(n).at(m))  n--;
		}
		if(m>0) 
		{
			if(s.at(n).at(m-1)+1==s.at(n).at(m))
			{
				m--;
				c.at(i)=b.at(m);
				i++;
			}
			else if(s.at(n).at(m-1)==s.at(n).at(m))  m--;
		}
	}
	for(i=c.size()-1;i>=0;i--) out<<c.at(i)<<" ";
}