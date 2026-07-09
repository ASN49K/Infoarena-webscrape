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
	freopen("euclid2.in", "rt", stdin);
	freopen("euclid2.out", "wt", stdout);
	
	int N, x, y;
	scanf("%d", &N);
	
	for(int i = 0; i < N; ++i)
	{
		scanf("%d %d", &x, &y);
		printf("%d\n", cmmdc(x, y));
	}
	
	return 0;
}
