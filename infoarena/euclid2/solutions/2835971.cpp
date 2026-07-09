#include <bits/stdc++.h>
using namespace std;

long a, b;

long gcd(long a, long b){
if(b==0){
    return a;
}
else if(a==0){
    return b;
}
else return gcd(b, a%b);
}



int main(){
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int n;
cin >> n;
while(n--){
    cin >> a >> b;
    cout << gcd(a, b) << "\n";
}
return 0;
}

