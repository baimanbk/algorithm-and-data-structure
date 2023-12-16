#include <iostream> 
#include <set>
using namespace std; 
int main(){ 
    int n; 
    cin >> n; 
    set <int> s; 
    for(int i=0; i<n; i++){ 
        int x; 
        cin >> x; 
        s.insert(x); 
    } 
    set <int> :: iterator iter; 
    for(iter=s.rbegin(); iter!=s.rend(); iter++){ 
        cout << *iter << " "; 
    } 
    return 0; 
}