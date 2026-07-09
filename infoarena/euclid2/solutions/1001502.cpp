#include <iostream>
#include <fstream>
using namespace std;

int a,b,c,t;


int main()
{




ifstream in("euclid2.in");
ofstream out("euclid2.out");
in>>t;



while(t!=0){

in>>a>>b;


while(b){
c=a%b;
a=b;
b=c;
}

out<<a;
out<<"\n";

t--;
}

    return 0;
}
