
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, a, b, ct;


ll cmmdc(ll a, ll b){
    while(b){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");

	fin >> a >> b;

	for(int i = 1; i <= n; i++){
	    fin >> a >> b;
        fout << cmmdc(a, b) << endl;

	}

	return 0;
}
