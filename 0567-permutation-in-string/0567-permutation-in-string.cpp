class Solution {
public:
    bool isFreqSame(int freq1[] , int freq2[]){
        for(int i=0 ; i<26 ; i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }



    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        for(auto it:s1){
            freq[it - 'a']++;
        }

        int win_size = s1.length();
        for(int it =0 ; it<s2.length() ; it++ ){
            int win_idx = 0 , idx = it;
            int win_freq[26] = {0};

            while(idx < s2.length() && win_idx < win_size){
                 win_freq[s2[idx] - 'a']++;
                 win_idx++;
                 idx++;
            }
            if(isFreqSame(freq , win_freq)){
            return true;
        }
        }
        
        return false;
    }
};