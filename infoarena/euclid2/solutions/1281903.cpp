#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a,int b)
{
    if(a%b==0)
        return b;
    return cmmdc(b,a%b);
}


int main()
{
    int a,b,result,cont;
    in>>cont;
    while(cont)
    {
        in >> a >> b;
        result = cmmdc(a,b);
        out << result<< "\n";
        cont--;
    }

    return 0;
}
