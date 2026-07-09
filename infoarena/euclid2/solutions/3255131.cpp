#include <iostream>
using namespace std;

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    
    int a, b, r,nr;
    
    in>>nr;
    for(int i=1;i<=nr;i++){
        in>>a>>b;
        while (b!=0) {
        r = a%b;
        a = b;
        b = r;
    }
    out<<a;
    }
    


    return 0;
}