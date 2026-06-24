class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& allsubset, vector<int>& ans , int i){
        if( i == nums.size()){
            allsubset.push_back(ans);
            return;
        }

        //include
        ans.push_back(nums[i]);
        helper( nums, allsubset, ans, i+1 );

        ans.pop_back(); // backtracking

        //skip if duplicates in the exlude
        int idx = i+1;
        while( idx< nums.size() && nums[idx] == nums[idx-1] ) idx++;
        
        //exclude
        helper( nums, allsubset, ans, idx);
        

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allsubset;
        vector<int> ans;
        helper( nums , allsubset , ans , 0);
        return allsubset;
    }
};