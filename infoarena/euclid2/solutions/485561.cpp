
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{

	freopen ("euclid2.out","w+",stdout);
	//freopen("euclid2.in","r",stdin);
	//cout << "asa da";
	int cases;
	int a,b;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		cin >> a>>b;
		while (a != b) {
			if (a > b) {
				a = a - b;
			} else {
				b = b - a;
			}
		}
		cout << a << endl;
	}
	fclose(stdout);
	return 0;
}
