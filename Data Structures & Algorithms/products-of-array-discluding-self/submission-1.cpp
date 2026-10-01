class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        int prod = 1;
        int zeroCount = 0;

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != 0){
                prod = prod * nums[i];
            }
            else{
                zeroCount++;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (zeroCount >= 2) {
                output.push_back(0);
            }
            else if (zeroCount == 1) {
                if (nums[i] == 0)
                    output.push_back(prod);
                else
                    output.push_back(0);
            }
            else {
                output.push_back(prod / nums[i]);
            }
        }

        return output;
    }
};
