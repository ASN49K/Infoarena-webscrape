//
//  main.cpp
//  Cmlsc
//
//  Created by Albastroiu Radu on 10/5/17.
//  Copyright © 2017 Radu Albastroiu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int d[2001][2001];

int main()
{
    
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> a, b;
    
    a.push_back(0);
    b.push_back(0);
    
    int aux;
    for(int i = 0; i < n; i++)
    {
        cin >> aux;
        a.push_back(aux);
    }
    for(int i = 0; i < m; i++)
    {
        cin >> aux;
        b.push_back(aux);
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
                d[i][j] = 1 + d[i-1][j-1];
            else
                d[i][j] = max(d[i][j-1], d[i-1][j]);
        }
    }
    
    vector<int> result;
    for(int i = n, j = m; i;)
    {
        if(a[i] == b[j])
        {
            result.push_back(a[i]);
            i--;
            j--;
        }
        else if ( d[i - 1][j] < d[i][j-1] )
            j--;
        else
            i--;
    }
    
    
    cout << result.size() << endl;
    reverse(result.begin(), result.end());
    for(auto &elem : result)
        cout << elem << " ";
    
    return 0;
}
