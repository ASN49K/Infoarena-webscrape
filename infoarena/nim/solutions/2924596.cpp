//
//  main.cpp
//  Proiect_oregatire
//
//  Created by Steve Warlock on 05.10.2022.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int n,t;
vector<int>v;
bool solve()
{
    fin >> n;
    int sum = 0;
    for(int i = 0; i < n; ++i)
    {
        int x;
        fin >> x;
        v.push_back(x);
        sum ^= x;
    }
    if(!sum)
        return false;
    return true;
}
int main() {
   
    fin >> t;
    while(t--)
    {
        if(solve())
            fout << "DA\n";
        else
            fout << "NU\n";
    }
    fin.close(),fout.close();
    return 0;
}
