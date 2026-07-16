class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int>mapST(256,-1);
        vector<int>mapTS(256,-1);

        for(int i=0 ; i<s.length() ; i++){
            char c1 = s[i];
            char c2 = t[i];
            // if both seeing first time 
            if(mapST[c1] == -1 && mapTS[c2] == -1){
                mapST[c1] = c2;
                mapTS[c2] = c1;
            }
            // checking if mapping already exists  and checking consistency 
            else if(mapST[c1] != c2 || mapTS[c2] != c1){
                return false;
            }
        }
        return true;
    }
};