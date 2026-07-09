#include <iostream>
#include <fstream>

using namespace std;






int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    long n,a, b,r;
    in>>n;
    for(int i=1; i<=n; i++){
    in>>a>>b;
while(b){
        r=a%b;
        a=b;
        b=r;}
    out<<a<<'\n';
    }


    return 0;
}
