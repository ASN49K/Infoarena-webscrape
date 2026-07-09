
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
	//freopen ("euclid2.out","w+",stdout);
	//freopen("euclid2.in","r",stdin);
	ifstream input( "euclid2.in" );
	ofstream output ("euclid2.out");
	int cases;
	long a,b;
	input >> cases;
	for (int i = 0; i < cases; i++) {
		input >> a>>b;
		output << go(a,b) << "\n";
	}
	//fclose(stdout);
	input.close();
	output.close();
	return 0;
}
