#include <fstream>
#include <math.h>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
//#include <unordered_map>
#include <iomanip>
#include <time.h>
#include <stdio.h>
#include <bitset>
#include <map>
#define MAX 500000000000
//#include <iostream>
//#include <windows.h>
#include <deque>
//#include "PEZai.h"
//#include <Tlhelp32.h>
using namespace std;
ifstream cin("jocul.in");
ofstream cout("jocul.out");
//ifstream cin("algsort.in");
//ofstream cout("algsort.out");
char num, vec[10000003];
bool Prel_str(string s[], char v[])
{
    vector<bool> k;
    k.push_back(true);
    for(int i = 0; i < sizeof(v); i++)
    {
        int supreme_ok = 0;
        for(int j = 0; j < 6; j++)
        {
            string c = s[j];
            int rev = c.size() - 1, ok = 1, p;
            if(i + 1 >= c.size()){
                int l = c.size();
                for(p = i; p >= i + 1 - l; p--)
                {
                    if(v[p] != c[rev]){
                        ok = 0;
                        break;
                    }
                    else
                        rev--;
                }
                if(ok == 1){
                    if(k[p + 1] == true){
                        supreme_ok = 1;
                        break;
                    }
                }
            }
        }
        if(supreme_ok == 1)
            k.push_back(true);
        else
            k.push_back(false);
    }
    if(k[sizeof(v)] == true)
        return true;
    return false;
}
int main()
{
    string s[10] = {"out" ,"puton", "in", "one", "input", "output"};
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        //vec[0] = '/0';
        cin.get();
        cin.get(vec, 10000001);
        for(int j = 0; j < sizeof(vec); j++)
        cout << vec[j] << " ";
        return 0;
        if(Prel_str(s, vec))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
