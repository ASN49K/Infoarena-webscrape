#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{int a,b,c,x;f>>x;for(int i=0; i<x; i++){f>>a>>b;while(b){c=a%b;a=b;b=c;}g<<a<<endl;}}
