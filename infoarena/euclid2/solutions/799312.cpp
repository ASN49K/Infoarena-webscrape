#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int,int);
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int n,a,b;
    in>>n;
    while(n--)
        {
            in>>a>>b;
            out<<cmmdc(a,b)<<endl;
        }
    return 0;
}
int cmmdc(int a,int b)
{
    if(!b)
        return a;
    else
        return cmmdc(b,a%b);
}

