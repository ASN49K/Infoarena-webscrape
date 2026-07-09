#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("cmmdc.in");
ofstream fout("cmmdc.out");
long a,b;
int euclid(int a,int b)
{
    if(!b)return a;
    return euclid(b,a%b);

}
int main()
{
     fin>>a>>b;
     fout<<euclid(a,b);
     fin.close();
     fout.close();
     return 0;
}

