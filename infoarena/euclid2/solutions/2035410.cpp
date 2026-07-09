#include<fstream>

int cmmdc(int,int);
int main()
{
    int n,a,b,i;

    std::ifstream in("euclid.in");
    std::ofstream out("euclid.out");
    in>>n;

    for(i = 0; i < n;i++)
    {
        in>>a>>b;
        out<<cmmdc(a,b)<<"\n";
    }
}

int cmmdc(int a, int b)
{
    int t;
    while (b != 0)
    {
        b = a % b;
        t = b;
        a = t;
    }
    return a;
}
