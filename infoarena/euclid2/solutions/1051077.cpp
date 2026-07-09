#include<fstream>
#include<iostream>
using namespace std;

int i,t,a,b,r;

int main (){

    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    in>>t;

    for(i=1;i<=t;i++)
    {   r=1;
        in>>a>>b;
        if(b>a)
            swap(a,b);
        while(r) {
            r=a%b;
            a=b;

            b=r;
        }

        out<<a<<'\n';

    }

    in.close();
    out.close();
    return 0;
}
