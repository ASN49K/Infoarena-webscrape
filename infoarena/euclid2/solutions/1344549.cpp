#include<iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in" );
ofstream g("euclid2.out");

int magic(int a,int b){
    while(a%b!=0){
        int rest=a%b;
        a=b;
        b=rest;
    } g<<b<<endl;

}
int main()
{
    int n;f>>n;
    for( int i=0;i<n;i++){
        int a,b;
        f>>a>>b;
        magic(a,b);

    }
}
