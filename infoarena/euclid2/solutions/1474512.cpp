#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream fin,fout;
    fin.open("euclid2.in",ios::in);
    fout.open("euclid2.out",ios::out);
    unsigned int t,nr_1,nr_2,rest;
    fin>>t;

    while(fin>>nr_1>>nr_2)
    {

        while(nr_2!=0)
        {
            rest=nr_1%nr_2;
            nr_1=nr_2;
            nr_2=rest;
        }
        fout<<nr_1<<"\n";
    }

    return 0;
}
