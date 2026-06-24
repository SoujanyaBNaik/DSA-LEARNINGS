class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& ans, int i ){
        if( i == nums.size()){
            ans.push_back({nums});
            return;
        }
        
        unordered_set<int> set;

        for(int idx=i ; idx< nums.size();idx++){
                // skip the dulipcates
                if( set.find(nums[idx])!= set.end())
                      continue;
                set.insert(nums[idx]);
                swap(nums[i],nums[idx]);
                helper( nums, ans, i+1);

                // backtracking
                swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        helper(nums, ans, 0);
        return ans;
    }
};