#include<fstream>
#include<vector>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

vector<int> solve(vector<int> a, vector<int> b)
{
	vector<int> s,c=a,d=b;
	if(!(a.size()*b.size())) return s;
	c.pop_back(); d.pop_back();
	c=solve(c,b);
	d=solve(a,d);
	s=((c.size()>d.size())?c:d);
	if(a.at(a.size()-1)==b.at(b.size()-1)) s.push_back(a.at(a.size()-1));
	return s;
}

int main()
{
	int n,m,i;
	in>>n>>m;
	vector<int> a,b,s;
	a.resize(n);
	b.resize(m);
	for(i=0;i<n;i++) in>>a.at(i);
	for(i=0;i<m;i++) in>>b.at(i);
	s=solve(a,b);
	out<<s.size()<<'\n';
	for(i=0;i<s.size();i++) out<<s.at(i)<<" ";
}