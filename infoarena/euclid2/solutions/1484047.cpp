#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int a, b , T;
    for(i=1;i<=T;i++)
        {in>>a>>b;

            while(a!=b)
                if(a>b)
                    a=a-b;
        else b=b-a;
        out<< b << "\n" ;
        }

    return 0;
}
