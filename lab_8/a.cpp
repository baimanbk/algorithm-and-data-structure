#include <iostream>
#include <unordered_map>
#include <string>
#include <set>
#include <algorithm>
#include <unordered_set>

using namespace std;

long long mod = 1e9+7;
long long p = 11;

string getHash(string s){
    long long h = 0;
    for(long long i = s.size()-1;i >= 0; i--){
        h = (h * p % mod + (s[i]-47))%mod;
    }
    return to_string(h);
}

int main() {
    long long n;
    cin >> n;
    set<string> hashes;
    pair<string, string> p[2*n];
    for(long long i = 0 ; i < 2 * n; i++){
        string s;
        cin >> s;
        p[i].first = getHash(s);
        p[i].second = s;
        hashes.insert(s);
    }
    int j = 0;
    for(long long i = 0; i < 2 * n; i++){
        set<string> :: iterator it = hashes.find(p[i].first);
        if(it != hashes.end()){
            cout << "Hash of string \"" << p[i].second << "\" is " << p[i].first <<'\n';
            j++;
            if(j == n){
                break;
            }
        }
    }
}
