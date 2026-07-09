#include <iostream>
#include <fstream>
using namespace std;

int solution[1025];
int finalSolution[1025];

void solve(int * a, int * b, int n, int m, int &kmax,int k=0, int pos1=0, int pos2=0) {
	
	if (pos1 >= n || pos2 >= m)
	{

		if (k > kmax)
		{
			kmax = k;

			for (int i = 0; i < kmax; i++)
				finalSolution[i] = solution[i];
		}
		
		return;

	}
	else 
	 {

		 for (int j = pos1; j < n; j++)
			 for (int i = pos2; i < m; i++)
			 {	
				 if (a[j] == b[i])
				 {
					 solution[k] = a[j];
					 solve(a,b,n, m, kmax, k + 1, j + 1, i + 1);
				 }
			 }

	}

	
}

int main() {
	int n, m;
	int * a, *b;

	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	f >> n >> m;

	 a = new int[n];
	 b = new int[m];

	for (int i = 0; i < n; i++)
		f >> a[i];

	for (int i = 0; i < m; i++)
		f >> b[i];

	int kmax = 0;

	if (m >= n)
		solve(a,b,n, m, kmax);
	else solve(b,a,m, n, kmax);

	g << kmax << endl;
	for (int i = 0; i < kmax; i++)
		g << finalSolution[i] << " ";

}
