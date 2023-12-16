#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    string s = "";
    vector<long long> hashs(n);
    for(int i = 0 ; i < n ;i++){
        cin >> hashs[i];
    }
    long long d = hashs[0] + 97;
    //cout << d << " ";
    s += d;
    for(int i = 1; i < n; i++){
        long long diff = hashs[i] - hashs[i-1]; 
        //cout << diff << " ";
        diff = diff / pow(2,i);
        //cout << diff << " ";
        diff+=97;
        //cout << diff << " ";
        s += diff;
    }
    cout << s;
}