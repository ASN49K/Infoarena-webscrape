#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    long long  T,a,b;
    in>>T;
    int i;
    long long r;
    for(i=1;i<=T;i++)
    {
        in>>a>>b;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        out<<a<<endl;
        
    }
    
    return 0;
}
