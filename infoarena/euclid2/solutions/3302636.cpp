#include<iostream>
#include<cmath>
using namespace std;


void run() {
    int a,b;
    cin>>a>>b;
    int r;
    while (b!=0) {
        r=b;
        b=a%b;
        a=r;
    }
    cout<<a;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        run();
        cout<<"\n";
    }
}