#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    string s = "";
    string s1 = "";
    for(int i = 0 ; i < n; i++){
        char x;
        cin >> x;
        if(x == 'a' || x == 'e' || x == 'i' ||x == 'o' || x == 'u'){
            s += x;
        }
        else{
            s1 += x;
        }
    }
    sort(s.begin(), s.end());
    sort(s1.begin(), s1.end());
    cout << s << s1;
}