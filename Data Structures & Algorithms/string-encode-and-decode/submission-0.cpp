class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) return "";
        vector<int> sizes;
        for(string& s : strs){
            sizes.push_back(s.size());
        }

        string res;
        for(int s : sizes){
            res.append(to_string(s));
            res.push_back(',');
        }
        res.push_back('#');
        for(string& s : strs){
            res.append(s);
        }
        return res;
    }

    vector<string> decode(string s) {
        if (s.empty()) return{};
        vector<int> sizes;
        int i = 0;
        while (s[i] != '#'){
            int j = i;
            while (s[j] != ','){
                j++;
            }
            sizes.push_back(stoi(s.substr(i, j - i)));
            i = j + 1;
        }
        i++;

        vector<string> str;
        for (int sz: sizes){
            str.push_back(s.substr(i, sz));
            i += sz;
        }

        return str;
    }
};
