class Solution {
public:
    string encode(vector<string>& strs) {
        string ret;
        for (string& s : strs) {
            ret += std::to_string(s.length()) + "#";  // delimiter
            ret += s;
        }
        return ret;
    }

    vector<string> decode(string s) {
        vector<string> ret;
        int i = 0;
        while (i < s.length()) {
            // read length until delimiter
            string curNum;
            while (i < s.size() && isdigit(s[i])) {
                curNum += s[i++];
            }
            i++; // skip delimiter '#'
            int length = std::stoi(curNum);
            ret.push_back(s.substr(i, length));
            i += length;
        }
        return ret;
    }
};
