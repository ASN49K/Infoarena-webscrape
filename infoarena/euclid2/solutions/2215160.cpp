//
//  main.cpp
//  000
//
//  Created by adrian ilisei on 21/06/2018.
//  Copyright © 2018 adrian ilisei. All rights reserved.
//

#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    if(b==0)
        return a;
    else
        return cmmdc(b, a%b);
}

int main()
{
    int n;
    fin>>n;
    int a, b;
    for(int i=0; i<n; i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a, b)<<"\n";
    }
    return 0;
}
