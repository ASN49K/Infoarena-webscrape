#include<iostream>
#include<fstream>
using namespace std;
int euclid(int A,int B)
{
    if(B==A)
        return A;
    if(A>B)
        return euclid(A-B,B);
    return euclid(A,B-A);}
    int main()
    {
        int t,a,b;
        ifstream f ("euclid2.in");
        ofstream g ("euclid2.out");
        f>>t;
        for(int i=1;i<=t;i++)
        {
            f>>a>>b;
            cout<<euclid(a,b)<<endl;
        }
    }
