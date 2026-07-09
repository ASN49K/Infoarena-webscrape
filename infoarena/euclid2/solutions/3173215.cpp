#include <bits/stdc++.h>

using namespace std;

int n, i, a, perechi = 0, d, x, y, rest, s = 0, smin = 100000, q, p;

bool isPrime(int n)
{
    int d;
    
    if(n <= 1)
    {
        return false;
    }
    if(n == 2 or n == 3)
    {
        return true;
    }
    if(n % 2 == 0 or n % 3 == 0)
    {
        return false;
    }
    for(d = 5; d * d <= n; d += 6)
    {
        if(n % d == 0 or n % (d + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ifstream fin("cmmmc.in");
    ofstream fout("cmmmc.out");
    
    fin >> n;
    
    for(i = 1; i <= n; i++)
    {
        fin >> a;
        
        if(isPrime(a) == true)
        {
            fout << 2 << " " << 1 << " " << a;
        }
        else
        {
            perechi = 1;
            smin = 100000;
            
            for(d = 1; d * d < a; d ++)
            {
                if(a % d == 0)
                {
                    perechi += 2;
                    
                    if(d == 1)
                    {
                        x = 1;
                    }
                    else
                    {
                        
                    x = d;
                    y = n / d;
                    
                    while(y != 0)
                    {
                        rest = x % y;
                        x = y;
                        y = rest;
                    }
                    
                    }
                    
                    if(x == 1)
                    {
                        s = d + a / d;
                        
                        if(s < smin)
                        {
                            q = d;
                            p = a / d;
                            smin = s;
                        }
                    }
                }
            }
            
            if(d * d == a)
            {
                perechi = 2;
            }
            
            fout << perechi << " " <<q << " " << p << '\n';
        }
    }
    
}