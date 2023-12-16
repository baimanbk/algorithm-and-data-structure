#include <iostream>
#include <climits>

using namespace std;

#define d 256

int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        int x,y;
        cin >> x >> y;
        string s1 = "";
        for(int j = x-1; j <= y-1; j++){
            s1+=s[j];
        }
        //cout << s1 << " ";
        int m = s1.size();
        int n = s.size();
        int k,f;
        int p = 0;
        int t = 0;
        int h = 1;
        int q = INT_MAX;
        int cnt = 0;
        for(k = 0 ; k < m-1; k++){
            h = (h*d)%q;
        }
        for (k= 0; k < m; k++) {
            p = (d * p + s1[k]) % q;
            t = (d * t + s[k]) % q;
        }
        for(k = 0 ; k <= n-m; k++){
            if(p == t){
                for (f= 0; f < m; f++) {
                if (s[k + f] != s1[f]) {
                    break;
                    }
                }
            

            if(f == m){
                cnt++;
                }
            }
            if (k < n - m) {
            t = (d * (t - s[k] * h) + s[k + m]) % q;
 
            // We might get negative value of t, converting
            // it to positive
            if (t < 0)
                t = (t + q);
            }
        }
        cout << cnt << '\n';
    }
}