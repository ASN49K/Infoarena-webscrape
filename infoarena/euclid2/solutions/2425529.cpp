#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int euclid(int a, int b)
{
    if(a==b)return a;
    else{
        if(a>b)return euclid(a-b,b);
        else return euclid(a,b-a);
    }
}
int main()
{
    unsigned int n;
    in>>n;
    unsigned int a,b;
    cout<<euclid(a,b);
    return 0;
}
