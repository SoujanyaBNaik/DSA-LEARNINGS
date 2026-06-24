class Solution {
public:
    void helper( vector<int>& nums, vector<vector<int>>& allsubset, vector<int> ans , int i){
         if( i == nums.size()){
           allsubset.push_back({ans});
           return;
         }

         //include
         ans.push_back(nums[i]);
         helper( nums, allsubset, ans, i+1 );

         ans.pop_back(); //backtracking

         //exclude
         helper( nums, allsubset, ans, i+1 );

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allsubset;
        vector<int> ans;

         helper(nums, allsubset, ans, 0);
         return allsubset;
    }
};