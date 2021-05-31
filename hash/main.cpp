#include <iostream>
#include <ctime>
using namespace std;

const int SIZE = 10010000;
const int BASE = 2017;
const int MOD = 1000000009;
int64_t powers[SIZE];
int64_t ahash[SIZE];
int64_t bhash[SIZE];

string r_str(int length) {
    static string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string result;
    result.resize(length);
    for (int i = 0; i < length; i++)
        result[i] = charset[rand() % charset.length()];
    return result;
}

void init_hash(const string &line, int64_t *h, int base, int mod, int len)
{
    h[0] = 0;
    for (int i = 1; i <= len; ++i)
    {
        h[i] = h[i - 1] * base % mod + (signed char)line[i - 1] % mod;
    }
}

void init_powers(int64_t *p, int base, int mod)
{
    p[0] = 1;
    for (int i = 1; i < SIZE; ++i)
    {
        p[i] = p[i - 1] * base % mod;
    }
}

int64_t get_hash(int64_t *h, int64_t *p, int mod, int len)
{
    return (h[len] - h[1] * p[len - 1] % mod + mod) % mod;
}

int main()
{
    unsigned int start_time = clock();
    for (int i = 1; i <= 1; i++)
    {
        string a, b;
        a = r_str(2);
        b = r_str(2);
        int len_a = a.length();
        int len_b = b.length();
        init_powers(powers, BASE, MOD);
        init_hash(a, ahash, BASE, MOD, len_a);
        init_hash(b, bhash, BASE, MOD, len_b);
        cout << a << "  " << b << "  ";
        int a_hash, b_hash;
        a_hash = get_hash(ahash, powers, MOD, len_a);
        b_hash = get_hash(bhash, powers, MOD, len_b);
        cout << a_hash << " " << b_hash << " ";
        if (a_hash == b_hash)
        {
            cout << "Identical\n";
        }
        else
        {
            cout << "Different\n";
        }
    }
    string c, d;
    unsigned int end_time = clock();
    unsigned int time = end_time - start_time;
    cout << time << endl;
    return 0;
}
