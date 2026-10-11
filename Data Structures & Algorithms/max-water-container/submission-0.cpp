class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int max_water = 0;

        while(l < r){
            int amt_water = (r - l) * min(heights[l], heights[r]);
            max_water = max(max_water, amt_water);
            if(heights[l] > heights[r]){
                r--;
            }
            else if(heights[l] < heights [r]){
                l++;
            }
            else{
                if(l < r && heights[l+1] > heights[r-1]){
                    l++;
                }
                else if(l < r && heights[l+1] < heights[r - 1]){
                    r--;
                }
                else if(l < r && heights[l+1] == heights[r - 1]){
                    l++;
                    r--;
                }
            }
        }

        return max_water;
    }
};
