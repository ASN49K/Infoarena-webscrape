#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int n;
    cin>>n;
    for(;n>0;--n){
        int a,b;
        cin>>a>>b;
        if(a<b) swap(a,b);
        while(b){
            a=a%b;
            swap(a,b);
        }
        cout<<a<<"\n";
    }
}
