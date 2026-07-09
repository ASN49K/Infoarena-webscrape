#include <fstream>
#include <cmath>
using namespace std;

int main()
{unsigned int a,b;
ifstream x("cmmdc.in");
ofstream y("cmmdc.out");
x>>a;
x>>b;
x.close();
while(a!=b){if(a>b) a=a-b; else b=b-a;}
y<<a;
y.close();
    return 0;
}
