#include <fstream>
#define limit 1024
#define mx(x, y) ((x>y) ? x:y)

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int A, B, a[limit], b[limit], nr[limit][limit], sir[limit], sir_length;

int main()
{
	int i, j;
	f >> A >> B;
	for (i = 1; i <= A; i++) f >> a[i];
	for (i = 1; i <= B; i++) f >> b[i];

	for (i = 1; i <= A; i++)
		for (j = 1; j <= B; j++) {
			if (a[i] == b[j]) nr[i][j] = 1 + nr[i - 1][j - 1];
			else nr[i][j] = mx(nr[i - 1][j], nr[i][j - 1]);
		}

	for (i = A, j = B; i; ) {
		if (a[i] == b[j]) {
			sir[++sir_length] = a[i];
			i--;
			j--;
		}
		else {
			if (nr[i - 1][j] < nr[i][j - 1]) j--;
			else i--;
		}
	}

	g << sir_length << '\n';
	for (i = sir_length; i >= 1; i--) g << sir[i] << ' ';

    return 0;
}
