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
    int n,A,B;
    in>>n;
    for (int i=1;i<=n;i++)
    {
        in>>A>>B;
        out<<euclid(A,B)<<endl;
    }

    in.close();
    out.close();
    return 0;
}
