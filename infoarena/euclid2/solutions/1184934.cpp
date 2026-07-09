#include <iostream>
#include <fstream>

using namespace std;

int main()

{ int i,a,b,c;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
f>>a;
for(i=1;i<=a;i++){
f>>b>>c;
while(b!=c){
if(b>c)b=b-c;
else c=c-b;}
g<<b;
g<<endl;
}


    return 0;
}
