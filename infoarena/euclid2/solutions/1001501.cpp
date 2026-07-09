#include <iostream>
#include <fstream>
using namespace std;

int a,b,c;


int main()
{

ifstream in("euclid2.in");
ofstream out("euclid2.out");
in>>a>>b;

while(b){

c=a%b;
a=b;
b=c;
}

out<<a;
out<<"\n";

    return 0;
}
