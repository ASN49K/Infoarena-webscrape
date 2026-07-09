#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <set>
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater

using namespace std;

//17:46

int gcd(int a, int b) {
	while (b) {
		return gcd(b, a%b);
	}
	return a;
}

int main() {
	freopen("euclid.out","w",stdout);
	freopen("euclid.in","r",stdin);
    int n, m, x, y;
   	cin>>n;
   	for (int i = 0; i < n; i++) {
   		cin>>x>>y;
   		cout<<gcd(x, y);
   	}
    
    return 0;
}
