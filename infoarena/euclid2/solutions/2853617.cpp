#include <bits/stdc++.h>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

pair <int, int> a;
int n;

int main(){
    in>>n;
    for(int i = 0; i<n; i++){
        in>>a.first>>a.second;
        out<<__gcd(a.first, a.second)<<"\n";
    }
}