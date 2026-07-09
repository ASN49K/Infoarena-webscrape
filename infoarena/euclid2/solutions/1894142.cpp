#include <fstream>

int euclid(int a, int b) {

	int c;

	while (b) {
		c = a;
		a = b;
		b = c % b;
	}

	return a;

}


int main() {

	int a, b, nr;

	std::freopen("euclid2.in", "r", stdin);
	std::freopen("euclid2.out", "w", stdout);

	scanf("%d", &nr);

	while (nr--) {

		scanf("%d%d", &a,&b);
		printf("%d\n",euclid(a, b));
	
	}

	return 0;

}