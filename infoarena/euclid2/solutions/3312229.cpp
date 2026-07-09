#include<bits/stdc++.h>

using namespace std;
int v[105];
int main(){

int n;
cin >> n;
int a, b;
for(int i = 1; i <= n ; ++i){
    cin >> a >> b;
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
v[i] = a;
}
for(int i = 1; i <= n ; ++i)
    cout << v[i] << endl;
return 0;}

