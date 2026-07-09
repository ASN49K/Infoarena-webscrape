//
//  main.cpp
//  CplusplusProjects
//
//  Created by Vlad Tuchilus on 11/03/2019.
//  Copyright © 2019 Vlad Tuchilus. All rights reserved.
//

#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int T, x, y;

int cmmdc(int a, int b){
    if(a >= b)
    {
        if(a % b == 0)
        {
            return b;
        }
        else
        {
            return cmmdc(a % b, b);
        }
    }
    if(b > a)
    {
        if(b % a == 0)
        {
            return a;
        }
        else
        {
            return cmmdc(a, b % a);
        }
    }
    return 1;
}

int main() {
    fin >> T;
    for(int i = 1; i <= T; i++)
    {
        fin >> x;
        fin >> y;
        fout << cmmdc(x,y) << endl;
    }
    return 0;
}
