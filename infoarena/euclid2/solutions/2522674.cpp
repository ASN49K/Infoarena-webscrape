#include <iostream>
#include <fstream>

using namespace std;






int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    long nr,a, b,rest;
    in>>nr;
    for(int i=1; i<=nr; i++){
    in>>a>>b;
while(b){
        rest=a%b;
        a=b;
        b=rest;}
    out<<a<<endl;
    }


    return 0;
}
