class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int mini = nums[0];
        int maxi = nums[nums.size()-1];
        return gcd(mini , maxi);
    }
};