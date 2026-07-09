#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <string.h>
#include <assert.h>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <math.h>
#include <limits.h>

using namespace std;

// MACROS
#define REP(i, a, b) \
	for (int i=int(a); i<=int(b); ++i)


typedef long long int ll;

// vector of int
typedef vector<ll> vi;

// int pair
typedef pair<ll,ll> ii;

// vector of int pairs
typedef vector<ii> vii;

typedef vector<vii> AdjList;


int ggt(int a, int b) {
	if (b == 0)
		return a;
	else
		return ggt(b, a%b);
}

int a, b;

int main () {

	ifstream f("euclid2.in");
	ofstream g("euclid2.out");

	int t;
	f >> t;
	while (t--) {
		f >> a >> b;
		g << ggt(a, b) << endl;
	}

	return 0;
}