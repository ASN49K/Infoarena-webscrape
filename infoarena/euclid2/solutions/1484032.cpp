#include <iostream>
#include <ftsream>
using namespace std;
 ifstream in("data.in")
 ofstream out("data.out")
int main()
{
    ifstream in("data.in")
 ofstream out("data.out")
    int a, b;
    in>>a>>b;
        while(a!=b)
            if(a>b)
                a=a-b;
    else b=b-a;
    out<< b ;
    return 0;
}
