#include<bits/stdc++.h>
using namespace std;
ifstream F("euclid2.in");
ofstream G("euclid2.out");
int a,b;
int main()
{
	for(F>>a;F>>a>>b;G<<__gcd(a,b)<<'\n');
	return 0;
}
