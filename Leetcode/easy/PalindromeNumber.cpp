class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string s1 = "";
        for(int i = s.size()-1 ; i >= 0; i--){
            s1 += s[i];
        }
        cout << s1 << " " << s;
        if(s1 == s){
            return true;
        }
        else return false;
        
    }
};