#include <iostream>
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a,int b){
    if(b==0) return a;
    return euclid(b,a%b);
}

int main()
{

    int n,nr1,nr2;
    in>>n;
    for(int i=1;i<=n;i++){
        in>>nr1;
        in>>nr2;
        out<<euclid(nr1,nr2)<<endl;
    }
    return 0;
}



