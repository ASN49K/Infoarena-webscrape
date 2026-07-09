#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ifstream fout("euclid2.out");

int cmmdc(long long a, long long b) {
    int r;
    
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    
    return a;
}

int main()
{
    long long n, i, a, b;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a >> b;
        cout << cmmdc(a,b) << endl;
    }
    
    return 0;
}
            
        

                