
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
long go ( long a, long b ){
	if ( b==0) return a;
	return go ( b, a%b);
}
int main()
{

	//cout << 10 % 5;
	freopen ("euclid2.out","w+",stdout);
	freopen("euclid2.in","r",stdin);
	int cases;
	long a,b;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		cin >> a>>b;
		cout << go(a,b) << endl;
	}
	fclose(stdout);
	return 0;
}
