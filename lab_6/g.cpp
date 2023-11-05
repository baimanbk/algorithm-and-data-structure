#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    map <string,string> v;
    for(int i = 0 ; i < n ; i++){
        string f;
        cin >> f;
        string l;
        cin >> l;
        bool b = false;
        map<string, string> :: iterator it;
        for(it = v.begin(); it != v.end() ; it++){
            if(it -> second == f){
            v[it->first] = l;
            b = true;
            break;
            }
        }
        if(!b){
            v[f] = l;
        }
    }
    cout << v.size() << '\n';
    map<string, string> :: iterator it;
    for(it = v.begin(); it != v.end() ; it++){
        cout << it->first << " " << it->second << '\n';
    }
}