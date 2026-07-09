#include <iostream>
#include <fstream>



using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int euclid (int a , int b)
{
    if (!b)
        return a;
    if (a>b)
        return euclid (a-b,b);
    return (a,b-a);
}

int main ()
{
    int a ,b ;
    fin>>a>>b;
    int c=euclid (a,b);
    fout<<c;

}
