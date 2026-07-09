#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
using namespace std;



int main()
{
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	int n, m, i, j = 0,it=0;
	deque <int> q;
	int h[1024];
	for (i = 0; i <= 257; i++) h[i] = 1025;
	f >> n >> m;
	for (i = 1; i <= n; i++)
	{
		f >> j;
		if(h[j]>i) h[j] = i;
	}
	deque <int> p;
	for (i = 1; i <= m; i++)
	{
		f >> j;
		if (h[j] != 1025){
			if (it < h[j]) {
				q.push_back(j);
				it = h[j];
			}
			else {
				if (p.size() < q.size()) p = q;
			
				while (it >= h[j] && !q.empty()){
					q.pop_back();
					if(!q.empty())it = h[q.back()];
				}
				q.push_back(j);
				it = h[q.back()];
			}
		}
	}
	if (p.size() < q.size()) p = q;
	g<< p.size() << "\n";
	while (!p.empty()){
		g << p.front() << " ";
		p.pop_front();
	}
	//cin.get();
	f.close();
	g.close();
	return 0;
}
