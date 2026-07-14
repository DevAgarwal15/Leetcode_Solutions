class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int i = 1 ; i<= 9 ; i++){
            int num = 0;

            for(int digit = i ; digit <= 9 ; digit++){
                num = (num * 10) + digit;

                if(num >= low && num <= high){
                    ans.push_back(num);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};