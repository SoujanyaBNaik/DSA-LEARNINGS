class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& ans, int i){
        if( i == nums.size())
        {
            ans.push_back({nums});
            return;
        }

        for(int idx=i;idx<nums.size();idx++){
            swap(nums[i],nums[idx]);
            helper( nums, ans, i+1);

            //backtracking
            swap(nums[i],nums[idx]);
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums, ans, 0);
        return ans;

    }
};