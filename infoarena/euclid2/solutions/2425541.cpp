#inclide <iostream>
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
    int n;
    in>>n;
    int a,b;
    out<<euclid(a,b)<<endl;
    return 0;
}
