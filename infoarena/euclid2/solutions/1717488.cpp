#include<iostream>
#include<fstream>
using namespace std;
struct num
{
	int a;
	int b;
}v[100];
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int t;
	f >> t;
	for (int i = 1; i <= t; ++i)
		f >> v[i].a >> v[i].b;
	for (int i = 1; i <= t; i++){
		while (v[i].a != v[i].b){
			if (v[i].a > v[i].b)
				v[i].a -= v[i].b;
			else
				v[i].b -= v[i].a;
		}
		g << v[i].a << endl;
	}
	f.close();
	g.close();
	return 0;
}