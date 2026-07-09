#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int cmmdc(int x, int y)
{
	if(y == 0)
		return x;
	if(y > x) swap(x, y);
	return cmmdc(y, x % y);
}

int main(){
	ifstream  in("euclid2.in");
	ofstream out("euclid2.out");
	
	int N, x, y;
	in >> N;
	
	for(int i = 0; i < N; ++i)
	{
		in >> x >> y;
		out << cmmdc(x, y) << endl;
	}
	
	return 0;
}
