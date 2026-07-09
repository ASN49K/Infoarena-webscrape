#include<iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in" );
ofstream g("euclid2.out");

int magic(long int a,long int b){
    while(b){
        long int rest=a%b;
        a=b;
        b=rest;
    } g<<a<<endl;
    return 1;
}
int main()
{
    int n;f>>n;
    for( int i=0;i<n;i++){
        long int a,b;
        f>>a>>b;
        magic(a,b);

    }
}
