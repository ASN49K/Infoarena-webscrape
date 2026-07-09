#include <iostream>
#include<fstream>
using namespace std;

int main()
{
    int a,b,i=0;
    long int n;
    ifstream f("euclid2.in");

    ofstream g("euclid2.out");
 f>>n;
    while(i<n){
 f>>a;f>>b;
    while(a!=b)
    {

        if(a>b)
        a=a-b;
        else b=b-a;
    }

g<<a<<endl; i++;}
    f.close();
    g.close();
    return 0;
}
