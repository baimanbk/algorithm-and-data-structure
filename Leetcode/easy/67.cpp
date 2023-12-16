class Solution {
public:
    string addBinary(string a, string b) {
        int A = a.length()-1;
     int B = b.length()-1;
     int i=0;
     int carry = 0;
     string ans = "";


     while(A>=0 || B>=0 || carry!=0)
     {
       if(A>=0)
       {
           carry+=a[A]-'0';
           A--;

       }
       if(B>=0)
       {
           carry+=b[B]-'0';
           B--;
       }
       ans+=(carry%2+'0');
       carry = carry/2;

     }
     reverse(ans.begin(),ans.end());

     return ans;
    
    }
};