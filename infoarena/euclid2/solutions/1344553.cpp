#include<iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in" );
ofstream g("euclid2.out");

int magic(float a,float b){
    while(a%b!=0){
        float rest=a%b;
        a=b;
        b=rest;
    } g<<b<<endl;
    return 1;
}
int main()
{
    int n;f>>n;
    for( int i=0;i<n;i++){
        float a,b;
        f>>a>>b;
        magic(a,b);

    }
}
