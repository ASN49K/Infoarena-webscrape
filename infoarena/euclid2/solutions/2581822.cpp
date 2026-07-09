#include <iostream>

using namespace std;
int cmmdc(int a, int b)
{
int d;
while (b != 0)
{
d = b;
b = a % b;
a = d;
}
return a;
}

