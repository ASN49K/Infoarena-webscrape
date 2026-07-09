#include <bits/stdc++.h>

using namespace std;

int main()
{
ifstream fi("euclid2.in");
ofstream fo("euclid2.out");
ios_base::sync_with_stdio(0);cin.tie(0);
int n,a,b;
fi >> n;
for(int i=0;i<n;i++)
{
fi >> a >> b;
fo << __gcd(a,b) << endl;
}
}
