#include <iostream>
#include <cstdio>
using namespace std;

int a,b,r,T;

int main(){
    cin.sync_with_stdio(false);

    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    cin>>T;

    while(T--){
        cin>>a>>b;
        while(b != 0){
            r = a % b;
            a = b;
            b = r;
        }
        cout<<a<<"\n";
    }

    return 0;
}
