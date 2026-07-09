#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    int a,b,t,i;

    in >> t;

    for(i=0;i<t;i++){
        in>>a>>b;

        while(a!=0&&b!=0){
            a>b?a=a%b:b=b%a;

    }
        if(a==0)
            out<<b<<"\n";
        else
            out<<a<<"\n";
    }

    return 0;
}
