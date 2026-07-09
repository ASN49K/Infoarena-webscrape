#include <iostream>
#include <stdio.h>
 
using namespace std ; 

int main(){
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        while(b){
            int c = a % b;
            a = b;
            b = c;
        }
        cout << a << '\n';
    }
	cout.flush();
    return 0;
}