#include <bits/stdc++.h>;

using namespace std;

int cmmdc(int a, int b){

if (a!=0) return cmmdc(b % a, a); else return b;



}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n;
    f>>n;
    for (int i=0; i<n; i++){
    int a,b;

 f>>a>>b;



g<<cmmdc(a,b)<<endl;

    }
    return 0;
}
