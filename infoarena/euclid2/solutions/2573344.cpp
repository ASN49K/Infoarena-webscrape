#include <iostream>
#include<fstream>
using namespace std;
int main()
{int a,b;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>a>>b;
while(a!=b)
{if(a>b)a=a-b;
else b=b-a;

}
g<<a;
    return 0;
}
