#include <iostream>
#include <stdio.h>
 
using namespace std ;
 
int main(){
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
    return 0;
}