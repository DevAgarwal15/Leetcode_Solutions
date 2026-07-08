class Solution {
public:

    int find_max(vector<int>& v){
        int maxi = INT_MIN;
        for(int i=0 ; i<v.size() ; i++){
            maxi = max(maxi , v[i]);
        }
        return maxi;
    }
    long long calculate_hrs(vector<int>& arr,int hourly){
        long long total_hour = 0;
        for(int i=0 ; i<arr.size() ; i++){
            total_hour += (arr[i] + hourly - 1LL) / hourly;
        }
        return total_hour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = 0;
        int low = 1;
        int high = find_max(piles);
        while(low <= high){
            int mid = low + (high-low)/2;
            long long total_hrs = calculate_hrs(piles,mid);
            if(total_hrs <= h){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};