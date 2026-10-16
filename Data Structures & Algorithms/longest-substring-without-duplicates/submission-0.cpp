class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        unordered_map<char,int> count;
        int length = 0;

        for(int r = 0; r < s.size(); r++){
            while(count[s[r]]){
                count[s[l]]--;
                l++;
            }

            count[s[r]]++;

            length = max(length, r - l + 1);

        }

        return length;
    }
};
