#include <iostream>
#include <fstream>
using namespace std;
int gcd(int a,int b){
    if(!b)
        return a;
    return gcd(b,a%b);
}
int main()
{
    fstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n;
    f>>n;
    for(int i=0;i<n;i++){
            int a,b;
    f>>a>>b;
    g<<gcd(a,b)<<'/n';}

}
