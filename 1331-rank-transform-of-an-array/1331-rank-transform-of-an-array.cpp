class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>sorted = arr;
        sort(sorted.begin(),sorted.end());

        unordered_map<int,int>rank;
        int r = 1;
        for(auto it:sorted){
            if(!rank.count(it)){
                rank[it] = r++;
            }
        }
        
        vector<int>ans;
        ans.reserve(arr.size());

        for(auto it:arr){
            ans.push_back(rank[it]);
        }
        return ans;

    }
};