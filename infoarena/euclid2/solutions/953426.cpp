#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>n;
int euclid(int a,int b)
{if (!b) return a;
    return euclid(b, a % b);
}

int main()
{int n,a,b;
while(n){f>>a>>b;g<<euclid(a,b)<<"/n";n--;}
f.close();g.close();
}
