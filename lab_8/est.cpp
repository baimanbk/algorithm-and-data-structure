#include <iostream>
#include <vector>

using namespace std;
const int p = 31;
const long long mod = 1e9 + 7;
long long get_hash(string s) {
    long long h = 0;
    long long p_pow = 1;

    for (char c : s) {
        h = (h + (c - 'a' + 1) * p_pow) % mod;
        p_pow = (p_pow * p) % mod;
    }

    return h;
}

int check_plagiarism(string s, string t) {
    int len = s.size() - t.size() + 1;
    int result = 0;

    long long hash_sub = get_hash(t);
    long long hash_s = get_hash(s.substr(0, t.size()));

    for (int j = 0; j < len; ++j) {
        if (hash_sub == hash_s) {
            result++;
        }
        if (j + t.size() < s.size()) {
            hash_s = (hash_s - (s[j] - 'a' + 1) + mod) % mod;
            hash_s = (hash_s * p + (s[j + t.size()] - 'a' + 1)) % mod;
        }
    }
    return result;
}

int main() {
    string s1, s2, sub;
    cin >> s1 >> s2 >> sub;

    int result_1 = check_plagiarism(s1, sub);
    int result_2 = check_plagiarism(s2, sub);

    if (result_1 < result_2) {
        cout << result_1;
    } else {
        cout << result_2;
    }

    return 0;
}
