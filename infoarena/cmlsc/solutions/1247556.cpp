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
	for (i = 0; i <= 257; i++) h[i] = 0;
	f >> n >> m;
	for (i = 1; i <= n; i++)
	{
		f >> j;
		h[j] = i;
	}
	int c = 0;
	for (i = 1; i <= m; i++)
	{
		f >> j;
		if (h[j] != 0){
			if (it < h[j]) {
				c++;
				q.push_back(j);
				it = h[j];
			}
			else {
				it = h[j];
				c =1;
				q.clear();
				q.push_back(j);
			}
		}
	}

	g<< c << "\n";
	while (!q.empty()){
		g << q.front() << " ";
		q.pop_front();
	}
	//cin.get();
	f.close();
	g.close();
	return 0;
}
