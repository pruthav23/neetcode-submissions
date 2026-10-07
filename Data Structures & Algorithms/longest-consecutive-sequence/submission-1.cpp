class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // unordered_set<int> numSet(nums.begin(), nums.end());
        // int longestStreak = 0;

        // for(int num : numSet){
        //     if(numSet.find(num - 1) == numSet.end()){
        //         int currentNum = num;
        //         int currentStreak = 1;
            

        //         while (numSet.find(currentNum + 1) != numSet.end()){
        //             currentNum++;
        //             currentStreak++;
        //         }

        //         longestStreak = max(longestStreak, currentStreak);

        //     }
        // }

        // return longestStreak;

        unordered_map<int, int> mp;
        int longestStreak = 0;

        for(int num : nums){
            if (!mp[num]){
                mp[num] = mp[num - 1] + mp[num + 1] + 1;
                mp[num - mp[num - 1]] = mp[num];
                mp[num + mp[num + 1]] = mp[num];
                longestStreak = max(longestStreak, mp[num]);
            }
        }

        return longestStreak;
    }
};
