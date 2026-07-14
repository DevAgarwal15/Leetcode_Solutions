class Solution {
public:


    bool alpha_Numeric(char c){
        if((tolower(c) >= 'a' && tolower(c) <= 'z') || (tolower(c) >= '0' && tolower(c) <= '9') ){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int low = 0 , high = s.length()-1;
        while(low < high){
            if(!alpha_Numeric(s[low])){
                low++;
                continue;
            }
            if(!alpha_Numeric(s[high])){
                high--;
                continue;
            }
            if(tolower(s[low]) != tolower(s[high])){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
};