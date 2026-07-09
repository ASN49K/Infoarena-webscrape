#include<bits/stdc++.h>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int v[105];
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
v[i] = a;
}
for(int i = 1; i <= n ; ++i)
    out << v[i] << endl;
return 0;}

