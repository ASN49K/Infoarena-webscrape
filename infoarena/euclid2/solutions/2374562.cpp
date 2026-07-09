#include <iostream>
#include <fstream>
using namespace std;
long long int a,b;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
int t;
f>>t;
    for(t;t>=1;t--){
    f>>a;
    f>>b;
    while(a!=b){
    if(a>b)a=a-b;
    if(a<b)b=b-a;
    }
    g<<a<<"\n";
    }
    f.close();
    g.close();
    return 0;
}
