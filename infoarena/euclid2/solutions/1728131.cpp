#include <iostream>
#include <fstream>
using namespace std;

int euclidAlg( int a, int b) {

	int r;
	while ((r = a%b))
	{
		a = b;
		b = r;
	}

	return b;

}
int main() {


		int sol, n;
		FILE *f = fopen("euclid2.in", "r"), *g = fopen("euclid2.out", "w");
		fscanf(f, "%d", &n);
		
		
		int a, b;
		for (int i = 0; i < n; i++)
		{
			fscanf(f, "%d%d", &a, &b);
			sol = euclidAlg(a, b);
			fprintf(g, "%d", sol); 
			fprintf(g, "\n");
		}

		return 0;

		


}
