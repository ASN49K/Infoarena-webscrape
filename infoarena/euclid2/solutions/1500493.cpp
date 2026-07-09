#include<iostream>
using namespace std;
int asdf(int a, int b){
    int c;
    while(b){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int a,b;
int main(){
    cin>>a>>b;
    cout<<asdf(a,b);
    return 0;
}
