class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int a = nums[i];
            int l = i + 1;
            int r = nums.size() - 1;

            if(a > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue; 

            while(l < r){
                if (nums[l] + nums[r] + nums[i] > 0){
                    r--;
                }
                else if (nums[l] + nums[r] + nums[i] < 0){
                    l++;
                }
                else{
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l < r && nums[l] == nums[l - 1]){
                        l++;
                    }
                }
            }
        }

        return res;
    }
};
