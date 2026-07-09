#include <iostream>
#include <cstdio>

using namespace std;

void gcd(int a, int b){
    int t;
    while(b){
        t=b;
        b=a%b;
        a=t;
    }
    cout << a << '\n';
}

int main()
{
    int T,x1,x2;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    for(int i=0;i<T;++i){
        cin >> x1 >> x2;
        gcd(x1,x2);
    }
    return 0;
}
