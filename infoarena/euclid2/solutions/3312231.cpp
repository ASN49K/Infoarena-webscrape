#include<bits/stdc++.h>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main(){

int n;
in >> n;
int a, b;
for(int i = 1; i <= n ; ++i){
    in >> a >> b;
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
cout << a;
}
return 0;}

