#include <bits/stdc++.h>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int t, a, b;
int euclid (int a, int b){
int c;
while(b)
    {
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{
    in >> t;
    for(int i = 1; i <=t; i++){
        in >>a>>b;
        out<<euclid(a, b)<<'\n';
    }

    return 0;
}
