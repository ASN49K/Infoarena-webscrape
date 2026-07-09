#include <iostream>
#include <fstream>
using namespace std;
int minimum(int a ,int b);
int main()
{
    int n;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(int i=0;i<n;i++){
        int a,b;
        f>>a>>b;
        for(int j=minimum(a,b);j>=1;j--){
            if(a%j==0 && b%j==0){
                g<<j<<endl;
                break;
            }
        }
    }
    return 0;
}
int minimum(int a,int b){
    if(a<b){
        return a;
    }
    else return b;
}
