#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int n,a,b;

int euclid(int x,int y){
    if(!y) return x;
    return euclid(y,x%y);
}

int main()
{
    int i;
    in>>n;
    for(i=1;i<=n;i++){
        in>>a>>b;out<<euclid(a,b)<<endl;
    }
    return 0;
}
