#include <bits/stdc++.h>

using namespace std ;

ifstream fin ("euclid2.in") ;
ofstream fout ("euclid2.out") ; 

int main(int argc, char const *argv[])
{
	int t ; 
	fin >> t ; 
	while (t --) {
		int a, b ; 
		// numbers 
		fin >> a >> b ; 
		fout << __gcd (a, b) << '\n' ;
	}
	return 0;
}