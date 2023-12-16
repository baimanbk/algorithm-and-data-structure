class Solution {
public:
    int lengthOfLastWord(string s) {
        string s1 = "";
        bool boolka = false;
        int cnt = 0;
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == ' ' &&boolka){
                break;
            }
            else if(s[i] != ' '){
                boolka = true;
                cnt++;
            }
        }
        return cnt;
    }
};