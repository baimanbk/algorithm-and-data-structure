#include <bits/stdc++.h>

using namespace std;

int main(){
    deque<int> d;

    while(true){
        char c;
        cin >> c;
        if(c == '!'){
            return 0;
        }
        else if(c == '+'){
            int x;
            cin >> x;
            d.push_front(x);
        }
        else if(c == '-'){
            int x;
            cin >> x;
            d.push_back(x);
        }
        else if(c == '*'){
            if(d.empty()){
                cout << "error" << '\n';
            }
            else{
                int a1 = d.front();
                int a2 = d.back();
                int sum = a1 + a2;
                cout << sum << '\n';
            }
            if(d.size() > 1){
                d.pop_back();
                d.pop_front();
            } else if(d.size() == 1){
                d.pop_back();
            }
    }
}
}