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

ll a, b, res;

ll ggt(ll a, ll b) {
	if (b == 0)
		return a;
	else
		return ggt(b, a%b);
}

int main () {

	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");

	int t;
	fin >> t;
	while (t--) {
		fin >> a >> b;
		fout << ggt(a, b) << endl;
	}

	return 0;
}