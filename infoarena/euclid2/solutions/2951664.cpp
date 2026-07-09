#include <iostream>
#include <set>
#include <string>
using namespace std;
int gcd(int a , int b){
    if(b!=0) gcd(b,b%a);
    else return a;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int a , b;
        cin  >> a >> b;
        cout << gcd(a,b);
    }


}