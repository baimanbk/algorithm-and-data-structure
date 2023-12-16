#include <iostream>
#include <vector>
using namespace std;

void computeLPSArray(string& pat, int m, int* lps);

void KMPSearch(string& txt, string& pat,vector<int>& v) {
    int m = pat.size();
    int n = txt.size();

    int lps[m];
    computeLPSArray(pat, m, lps);

    int i = 0, j = 0;
    while (i < n) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == m) {
            v.push_back((i-j)+1);
            j = lps[j - 1];
        } else if (i < n && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

void computeLPSArray(string& pat, int m, int* lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main() {
    string pat, txt;
    getline(cin, txt);
    getline(cin, pat);
    vector<int> v;
    KMPSearch(txt,pat,v);
    cout << v.size() <<'\n';
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    return 0;
}
