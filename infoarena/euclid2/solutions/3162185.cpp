#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f ("euclid2.in");
    ofstream g ("euclid2.out");
    int n,a,b,c;
    f>>n;
    while (n>0){
        f>>a>>b;
        if (a<b){ c=a; a=b; b=c;}
        while (a%b!=0){
           c=b;
           b=a%b;
           a=c;
        }

        g<<b<<endl;

        n--;
}



    return 0;
}
