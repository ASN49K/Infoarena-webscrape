#include<fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int euclid(int a,int b)
{
    if(b == 0)
        return a;
    else
        return euclid(b,a%b);
}
int main()
{
    int t,c;
    int a,b;
    in>>t;
    while(t>0)
    {
        in >> a >>b;
        out << euclid(a,b) << endl;
        t--;
    }
    return 0;
}
