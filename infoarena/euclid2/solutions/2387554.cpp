#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int T,a,b;
    in>>T;
    for(int i=1;i<=T;i++){
    in>>a;
    in>>b;
    while (a!=b)
        if(a>b)
            a=a-b;
        else
            b=b-a;
        out<<a<<endl;
    }
    
    return 0;
}
