#include <iostream>
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int n;
    in>>n;
    for(int i=1;i<=n;i++){in>>a>>b;
    while(a!=b)
        if(a>b)a=a-b;
    else b=b-a;
    out<<a<<endl;
    }
        return 0;
}
