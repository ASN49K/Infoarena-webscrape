#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b, c;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a >> b;
        if(a < b)
            swap(a, b);
        if(a % b == 0){
            cout << b << '\n';
            continue;
        }
        while(a != b){
            c = a;
            a = a % b;
            b = c;
        }
        cout << a << '\n';
    }
    return 0;
}