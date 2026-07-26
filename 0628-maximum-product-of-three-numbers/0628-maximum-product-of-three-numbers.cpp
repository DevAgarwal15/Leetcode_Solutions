class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int first = INT_MIN, second=INT_MIN , third = INT_MIN;
        int min1=INT_MAX , min2 =INT_MAX;
        for(auto it:nums){
            if (it > first) {
                third = second;
                second = first;
                first = it;
            }
            else if (it > second) {
                third = second;
                second = it;
            }
            else if (it > third) {
                third = it;
            }
            if(min1 >= it){
                min2 = min1;
                min1 = it;
            }
            else if(min2 >= it){
                min2 = it;
            }
        }
        long long p1 = first*second*third;
        long long p2 = min1*min2*first;
        return max(p1,p2);
    }
};