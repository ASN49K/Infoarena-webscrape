#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int i =1; i <= t; i++){
        int a,b;
        cin >> a >> b;
        while(a!=b){
            if ( a > b)a-=b;
            else b-=a;
        }
        cout << b << endl;
    }
}
