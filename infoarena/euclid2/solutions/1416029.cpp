#include <iostream>
#include <fstream>

using namespace std;

int CMMDC(int a, int b){
    int c;
    while(a>0){
        c=a;
        a=b%a;
        b=c;
    }
    return b;
}

int main()
{
    int a,b,T;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in >> T;
    for(int i=1;i<=T;i++){
        in >> a >> b;
        out << CMMDC(a,b) << '\n';
    }
}
