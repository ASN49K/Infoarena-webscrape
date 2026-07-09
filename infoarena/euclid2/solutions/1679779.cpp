#include<bits/stdc++.h>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int T, a, b;
int euclid(int a, int b);
void citire(){
    f>>T;
    for(int i = 1; i <= T; i++){
        f>>a>>b;
        g<<euclid(a, b)<<"\n";
        }
    }

int euclid(int a, int b){
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    citire();
}
