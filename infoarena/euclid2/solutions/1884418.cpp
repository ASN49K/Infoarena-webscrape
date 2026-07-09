#include <bits/stdc++.h>
using namespace std;
int s;

int main()
{
    ifstream input;
    ofstream output;
    input.open("euclid2.in");
    input>>s;
    int a[s+1][3];
    for (int i=1;i<=s;i++){
        input>>a[i][1]>>a[i][2];
    }
    input.close();
    output.open("euclid2.out");
    for (int i=1;i<=s;i++){
        cout<<__gcd(a[i][1],a[i][2])<<"\n";
    }
    output.close();

}
