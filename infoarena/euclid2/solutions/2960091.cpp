#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b,int r)
{
if(a*b==0) return a+b;
if(r==0) return b;
else return cmmdc(b,r,a%b);
}
int main()
{
int a,b,r, t;
fin >> t;
for(int z = 0; z < t; ++z) {
fin>>a>>b;
r=a%b;
fout<<cmmdc(a,b,r) << "\n";}
return 0;
}
/*void functie(int a, int b) {
    if(a > b) {
            a -= b;
    }
    else if(a < b) {
        b -= a;
    }
    else if(a == b) {
        cout << a << endl;
    }
}*/
