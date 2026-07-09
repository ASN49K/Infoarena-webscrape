#include <bits/stdc++.h>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int n,a,b;

int main() {
    in>>n;
    while(n--){
        in>>a>>b;
        int i=0;
        do{
            i=a%b;
            a=b;
            b=i;
        }while(b);
        out<<a<<endl;
    }
    return 0;
}
