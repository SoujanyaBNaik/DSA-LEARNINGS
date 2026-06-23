class Solution {
public:
    int helper(vector<int>& nums, int target, int st, int end){
        if(st<=end){
        int mid= st+(end-st)/2;

        if( target == nums[mid]) 
             return mid;
        if( target <= nums[mid]){
            return helper(nums,target,st,mid-1);
        }
        else{
            return helper(nums,target,mid+1,end);
        }
        }
        return -1;

    }
    int search(vector<int>& nums, int target) {
        int st=0, end= nums.size()-1;
        return helper( nums, target, st, end);
        
    }
};