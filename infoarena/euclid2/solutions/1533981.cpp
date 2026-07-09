#include<fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int euclid(int a,int b)
{
    int c;
    while(b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{
    int i,t;
    int a,b;
    in>>t;
    for(i = 0;i < t; i++)
    {
        in >> a >>b;
        out << euclid(a,b) << endl;
    }
    return 0;
}
