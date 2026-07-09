#include<iostream>
#include<fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

int cmmdc(int a, int b)
{
    int x = (a<b) ? a : b;
    int result = 0;
    int i =x;
    while(i>1)
    {
        if((b%i == 0)&&(a%i == 0))
            break;
        i--;
    }
    return i;
}

int main()
{
    std::ifstream ifs("euclid2.in");
    std::ofstream ofs ("euclid2.out", std::ofstream::out);

    int a,b;
    std::string astr;
    std::string bstr;
    std::string nstr;


    std::getline(ifs,nstr);
    int n = atoi( nstr.c_str() );

        for(int i = 0;i<n;i++)
        {
            std::getline(ifs,astr,' ');a = atoi( astr.c_str() );
            std::getline(ifs,bstr); b = atoi( bstr.c_str() );
            ofs<<cmmdc(a,b)<<"\n";
        }

      ifs.close();
      ofs.close();
    return 0;
}
