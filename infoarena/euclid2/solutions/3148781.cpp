#include <iostream>
#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int eu(int a,int b){
    if(!b) return a;
    return eu(b,a%b);
}

int main(){
    int a,b,n;
    cin>>n;
    for(;n>0;n--){
    cin>>a>>b;
    cout<<eu(a,b)<<endl;
    }
    
}