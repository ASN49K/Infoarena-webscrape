#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid.in");
ofstream out("euclid.out");
int euclid(int a,int b){
if(!b) return a;
 return euclid(b,a%b);
}

int main(){int n;
in>>n;int mini,a,b;
for(int i=1;i<=n;i++){
    in>>a>>b;
    out<<euclid(a,b)<<" ";
}
return 0;}
