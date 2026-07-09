#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>

using namespace std;

//#include <iostream>
#include <fstream>

//ifstream cin ("input.in");
//ofstream cout ("output.out");

ifstream cin ("euclid2.in");
ofstream cout ("euclid2.out");

int main() {
	int t, a, b;
	cin>> t;
	for ( int i =1; i<=t; i++) {
		cin >> a>>b;
		while (b>0) {
			int r=a%b;
			a=b;
			b=r;
		}
		cout <<a<<'\n';
	}
}