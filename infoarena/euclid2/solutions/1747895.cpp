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
	if (b) {
		return gcd(b, a%b);
	}
	else
		return a;
}

int main() {
	ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    int n, m, x, y;
   	cin>>n;
   	for (int i = 0; i < n; i++) {
   		cin>>x>>y;
   			
   		cout<<gcd(x, y)<<endl;
   	}
    
    return 0;
}
