#include <bits/stdc++.h>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main() {
    int t;
    in >> t;
    for(int i =1; i <= t; i++){
        int a,b;
        in >> a >> b;
        while(b){
            int r = n%b;
            a = b;
            b = r;
        }
        out << a << endl;
    }
}
