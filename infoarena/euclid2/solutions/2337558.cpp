#include <iostream>
#include <fstream>
using namespace std;


int  cmmdc (int a, int b)
{
    while(a!=b)
    {
        if(a>b)
        a-=b;
        else
        b-=a;
    }
    return a;
}

int main()
{

    ifstream in("euclid2.in");
    ofstream out("euclid2.out");






    int n,a,b;
    in>>n;
    while(n)
    {
        in>>a>>b;
        out<<cmmdc(a,b)<<endl;
        n--;
    }


    return 0;
}
