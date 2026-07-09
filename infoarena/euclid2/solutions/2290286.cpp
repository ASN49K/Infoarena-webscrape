#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int nr1,nr2,no;
    int r;
    fin>>no;
    for(int i=0;i<no;i++)
    {
    fin>>nr1>>nr2;
    {

    while(nr2)
    {
        r = nr1 % nr2;
        nr1 = nr2;
        nr2 = r;
    }
    fout<<nr1<<"\n";
}
    }
}
