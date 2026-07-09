#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int cmmdc(int x, int y)
{
	while(y != 0){
		if(y > x) swap(x, y);
		int tmp = y;
		y = x % y;
		x = tmp;
	}
	return x;
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
