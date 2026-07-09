#include<fstream>
#include<iostream>
using namespace std;
bool v[2000001];
ifstream in("ciur.in");
ofstream out("ciur.out");
int euclid(int a,int b)
{
    if(b==0)
        return a;
    if(a>b)
        return euclid(a%b,b);
    else
        return euclid(b,b%a);
}
int main()
{
    int n,nr=0,a,b;
    cin>>a>>b;
    cout<<euclid(a,b);

}
