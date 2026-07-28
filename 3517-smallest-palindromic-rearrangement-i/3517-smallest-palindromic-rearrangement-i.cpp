class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>freq (26,0);
        // Storing The Freq
        for(auto ch:s){
            freq[ch - 'a']++;
        } 

        string left = "";
        string middle = "";
        // building left half and middle string
        for(int i=0 ; i<26 ; i++){
            left.append(freq[i]/2,char('a'+i));

            if(freq[i] % 2 == 1){
                middle = char('a' + i);
            }
        }
        // now building the right half of the string
        string right = left;
        reverse(right.begin(),right.end());

        return left + middle + right ;
    }
};