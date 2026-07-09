#include <iostream>
#include<fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,T;
int cmmdc(int a,int b)
{
    int r;
    while(b!=0){
        r = b;
        b = a%b;
        a = r;
    }
    return a;
}

int main()
{
    f>>T;
    for(int i=1;i<=T;i++){
        f>>a>>b;
        g<<cmmdc(a,b)<<endl;
    }
    f.close();
    g.close();
}
