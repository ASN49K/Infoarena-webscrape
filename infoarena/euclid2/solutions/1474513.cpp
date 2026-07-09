#include <fstream>
int main()
{
    std::fstream fin,fout;
    fin.open("euclid2.in",std::ios::in);
    fout.open("euclid2.out",std::ios::out);
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
