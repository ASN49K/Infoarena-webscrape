#include <bits/stdc++.h>
using namespace std;

int main(){

    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int T, A, B;

    cin >> T;
    while(T--)
    {
        cin >> A >> B;
        cout << __gcd(A, B);
    }



return 0;
}

