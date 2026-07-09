#include <iostream>

using namespace std;

int main()
{

	int N, v[500][500], i, j, div, gasit;
	cin >> N;

	for (i = 0; i < N; i++) {
		for (j = 0; j < 2; j++) {
			cin >> v[i][j];
		}
	}
	j = 0;
	for (i = 0; i < N; i++) {
		for (div = 1; v[i][j] >= div && v[i][j + 1] >= div; div++) {
			if (v[i][j] % div == 0 && v[i][j + 1] % div == 0) {
				gasit = div;
			}
		}
		cout << gasit << endl;
	}
	return 0;
}
