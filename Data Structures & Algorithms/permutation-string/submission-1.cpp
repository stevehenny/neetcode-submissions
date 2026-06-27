class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        unordered_map<char, int> s1Map;
        unordered_map<char, int> s2Map;
        unordered_map<char, int> test;


        for(int i = 0; i < s1.length(); i++){
            s1Map[s1[i]]++;

            // init s2Map
            s2Map[s2[i]]++;
        }
        // test['a'] = 1;
        // test['b'] = 1;
        // if(test == s1Map){
        //     cout << "True" << '\n';
        // }
        // for(auto &[k,v]: s2Map){
        //     cout << k << ": "<< v << '\n'; 
        // }
        int left{};
        for(int right = s1.length(); right < s2.length(); right++){
            if(s1Map == s2Map){
                return true;
            }

            s2Map[s2[left]]--;
            if(s2Map[s2[left]] == 0){
                s2Map.erase(s2[left]);
            }
            left++;
            s2Map[s2[right]]++;

        }

        if(s1Map == s2Map){
            return true;
        }
        // for(auto &[k,v]: s2Map){
        //     cout << k << ": "<< v << '\n'; 
        // }



        return false;

    }
};
