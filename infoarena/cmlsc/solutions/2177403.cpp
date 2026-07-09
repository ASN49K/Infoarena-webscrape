#include <bits/stdc++.h>
#include <cassert>

using namespace std;

fstream f ("cmlsc.in", ios::in);
fstream g ("cmlsc.out", ios::out);

uint16_t n, m;
vector<int32_t> vec_a, vec_b, vec_c;

int main()
{
    assert(f >> m >> n);
    for(int i = 0, a; i < m; i++) { assert(f >> a); vec_a.push_back(a); }
    for(int i = 0, a; i < n; i++) { assert(f >> a); vec_b.push_back(a); }

    for(int i = 0; i < vec_a.size(); i++)
        if(find(vec_b.begin(), vec_b.end(), vec_a[i]) != vec_b.end())
            vec_c.push_back(vec_a[i]);

    assert(g << vec_c.size() << "\n");
    for(int i = 0; i < vec_c.size(); i++) assert(g << vec_c[i] << " ");
    return EXIT_SUCCESS;
}
