#include <cstdio>
#include <vector>
using namespace std;

class hash_table {

    static const int MOD = 666013;
    vector <long long> hash[MOD];
public:

    void insert (const long long &value) {

        hash[value % MOD].push_back (value);

    }

    bool check (const long long &value) {

        int map = value % MOD;
        for (vector <long long> :: iterator i = hash[map].begin (); i != hash[map].end (); ++i)
            if (*i == value)
                return 1;
        return 0;

    }

};

hash_table H;

int main () {

    freopen ("euclid.in", "r", stdin);
    freopen ("euclid.out", "w", stdout);

}
