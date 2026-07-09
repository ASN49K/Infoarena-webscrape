#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdarg>
using namespace std;

ifstream in("puterik.in");
ofstream out("puterik.out");
struct joj {int a;int b;};

int euclid(int a,int b)
{
    if(b==0) return a;
    else euclid(b,a%b);
}

int main()
{
    int* load=new int;
    int* a=new int;
    int* b=new int;
    in>>(*load);
    for(register int i=1;i<=*load;i++)
    {
        in>>*a;
        in>>*b;
        out<<euclid(*a,*b);
        out<<endl;
    }
    delete a,b,load;
}

