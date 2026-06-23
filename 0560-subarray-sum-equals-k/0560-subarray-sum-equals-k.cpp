class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        int count=0;
        vector<int> prefixSum(n, 0);
        prefixSum[0]=nums[0];
        for(int i=1; i< n;i++){
            prefixSum[i]= nums[i]+prefixSum[i-1];
        }
        unordered_map<int, int> map;
        for( int i=0; i<n ;i++){
            if( prefixSum[i] == k) count++;
            int val = prefixSum[i]-k;
            if( map.find(val)!=map.end()) 
             {
                count+= map[val];
             }
             
             map[prefixSum[i]]++;



        }
       return count;


    }
};