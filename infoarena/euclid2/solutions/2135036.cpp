#include <iostream>
#include <fstream>
using namespace std;
int divmax(int a ,int b){
    int r;
    while (b){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int t,a,b;
    in>>t;
    for (int i=1;i<=t;i++){
        in>>a>>b;
        cout<<a<<' '<<b<<endl;
        out<<divmax(a,b)<<"\n";

    }
    return 0;
}
