#include<bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

class Fuckyou {
	struct my {
		int a, b;
	} v[100100];
		int n;
	public:
		inline int cmmdc(int x,int y) {
			if (y == 0) return x;
			return cmmdc(y, x%y);
		}

		inline void fuck() {
			fin >> n;
			for (int i(1);i <= n;i++)
				fin >> v[i].a >> v[i].b;
			
			for (int j(1);j <= n;j++)
				fout << cmmdc(v[j].a,v[j].b);
		}
};


int main() {
	Fuckyou n;
	n.fuck();
	return 0;
}
