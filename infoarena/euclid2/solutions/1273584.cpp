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

#define DMAX 1005
#define DMAX2 2000003
#define MOD  1000003
#define min(a,b) a>b ? b : a
#define maxm(a,b) a<b ? b : a

int T, a, b;

int gcd(int a, int b){
    if(a%b == 0) return b;
    else return gcd(b, a%b);
}

int main(){
    int i;

	freopen("euclid2.in", "r", stdin); // euclid2
	freopen("euclid2.out", "w", stdout); // cautbin

    scanf("%d", &T);

    for(i=1; i<=T; i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", gcd(a,b));
    }

	return 0;
}
