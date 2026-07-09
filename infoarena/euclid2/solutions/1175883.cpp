/*#include <fstream>
using namespace std;
*/
#include <stdio.h>

int cmmdc(int a, int b)
{
	int c;
	while (b) {
		c = a;
		a = b;
		b = c % b;
	}
	return a;
}


int main()
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "r", stdout);
	
	int T, a, b;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", cmmdc(a, b));
	}

	/*ifstream input;
	ofstream output;
	input.open("euclid2.in");
	output.open("euclid2.out");
	int T, a, b;
	
	
	input >> T;
	for (int i = 0; i < T; i++) {
		input >> a >> b;
		output << cmmdc(a, b) << endl;
	}
	
	input.close();
	output.close();
	*/


	return 0;
}