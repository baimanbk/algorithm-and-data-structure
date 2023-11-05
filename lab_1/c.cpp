#include <bits/stdc++.h>

using namespace std;

int equalstr(string& s){
    int id = 0;
    for(int i = 0 ; i < s.size(); i++){
        if(s[i] != '#'){
            s[id] = s[i];
            id++;
        }
        else if(s[i] == '#' && id >= 0){
            id--;
        }
        else if(id < 0){
            id = 0;
        }
    }
    return id;
}

int main(){
    string s,t;
    cin >> s >> t;
    if(equalstr(s) == equalstr(t)){
        cout << "Yes" << '\n';
    }
    else cout << "No" << '\n';
}