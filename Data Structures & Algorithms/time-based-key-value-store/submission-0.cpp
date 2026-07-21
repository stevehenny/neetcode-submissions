class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> lookup;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        lookup[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto it = lookup.find(key);
        if (it == lookup.end()) {
            return "";
        }

        const auto& vec = it->second;

        int l = 0;
        int r = vec.size() - 1;
        int ans = -1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (vec[m].first <= timestamp) {
                ans = m;          
                l = m + 1;        
            } else {
                r = m - 1;        
            }
        }

        return ans == -1 ? "" : vec[ans].second;
    }
};