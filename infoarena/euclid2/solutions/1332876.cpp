#include <iostream>
#include <fstream>


using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a,int b)
{
    if(!b)
        return a;
    else
        return euclid(b,a%b);
}
int main()
{
    int n,a,b;
    in>>n;
    for (int i=1;i<=n;i++)
    {
        in>>a>>b;
        out<<euclid(a,b)<<endl;
    }

    in.close();
    out.close();
    return 0;
}
