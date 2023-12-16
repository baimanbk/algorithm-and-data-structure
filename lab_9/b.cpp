#include <iostream>
using namespace std;

void computeLPSArray(string& pat, int m, int* lps);

void KMPSearch(string txt, string pat, int& d) {
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
            d++;
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
    string txt, pat;
    cin >> txt;
    int x;
    cin >> x;
    cin >> pat;
    int i = 1;
    int d = 0;
    KMPSearch(pat, txt, d);
    //cout << d;
    if(d >= x){
        cout << "YES";
        //cout << x;
        return 0;
    }
    cout << "NO";
    return 0;
}
