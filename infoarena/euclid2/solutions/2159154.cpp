#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int a,b,t;

int euclid(int a,int b){
    int r = a % b;
    while(b){
        a = b;
        b = r;
        r = a%b;
    }
    return a;
}

int main()
{
    in>>t;
    for(int i = 0 ; i < t; i ++){
        in>>a>>b;
        out<<euclid(a,b)<<"\n";
    }
    return 0;
}
