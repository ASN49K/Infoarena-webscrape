#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,x,y;
int euclid(int a,int b){
    while(b){
        int c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{
    f>>n;
    while(n){
        f>>x>>y;
        if(x<y)
            swap(x,y);
        g<<euclid(x,y)<<'\n';
        n--;
    }
    return 0;
}
