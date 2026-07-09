#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main(){
    int a, b,nr,r;
    cin>>nr;
        while(nr!=0){
        cin>>a;
        cin>>b;
        while(b!=0){
            r=a%b;
            a=b;
            b=r;
        }
        nr--;
        cout<<a<<"\n";
    }
}
