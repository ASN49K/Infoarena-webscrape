//Link :

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");
//#define cout out

void solve(int a, int b){
    while (a != b && a != 0 && b != 0){
        if (a > b){
            a = a % b;
        }else{
            if (b > a){
                b = b % a;
            }
        }
    }
    out << max(a, b) << '\n';
}

int main(){
    int a, b, t;
    in >> t;
    while(t--){
        in >> a >> b;
        solve(a, b);
    }

    in.close();
    out.close();
}

