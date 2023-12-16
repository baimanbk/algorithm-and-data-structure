class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        sort(strs.begin(), strs.end());
        string f = strs[0];
        string l = strs[strs.size()-1];
        for(int i = 0 ; i < min(f.size(), l.size()); i++){
            if(f[i] != l[i]){
                return s;
            }
            s+=f[i];
        }
        return s;
    }
};