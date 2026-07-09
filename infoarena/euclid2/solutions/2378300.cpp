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

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main() {
    fin >> T;
    for(int i = 1; i <= T; i++)
    {
        fin >> x;
        fin >> y;
        fout << gcd(x,y) << endl;
    }
    return 0;
}
