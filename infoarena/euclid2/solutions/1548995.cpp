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

        while(a!=b){
        if(a>b)
           a=a-b;
        else
            b=b-a;
    }
        out << b <<"\n";
    }

    return 0;
}
