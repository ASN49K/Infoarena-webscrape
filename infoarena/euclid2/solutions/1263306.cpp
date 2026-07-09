#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <string>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstring>
using namespace std;

#define DMAX 100002
#define MOD  1000003
#define min(a,b) a>b ? b : a
#define max(a,b) a<b ? b : a

int T;

int gcd(int a, int b){
	if (a%b == 0) return b;
	else return gcd(b, a%b);
}

int main(){
	int i, j, a, b;

	freopen("euclid.in", "r", stdin); // test
	freopen("euclid.out", "w", stdout); // cautbin

	scanf("%d", &T);
	for (i = 0; i < T; i++){
		scanf("%d %d", &a, &b);
		printf("%d\n", gcd(a,b));
	}

	return 0;
}