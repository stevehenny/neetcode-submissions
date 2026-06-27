//1. check if s1 is longer -> return false
//2. initialize hash vectors for lower case char frequencies
// 3. generate a sliding window of s1.length() chars
// 4. loop through and slide window to see if hash vectors ever match
// 5. if they ever do -> return true
// 6. end of algo -> return false;

// s1 = "abc"
// s2 = "lecabee"
// hash1, hash as vectors


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.length() > s2.length()) return false;

        int k = s1.length();
        vector<int> hash1(26, 0);
        vector<int> hash2(26, 0);
        // initialize both hash1 and hash2
        for(int i = 0; i < k; ++i){
            hash1[s1[i] - 'a']++;
            hash2[s2[i] - 'a']++;
        }

        for(int i = k; i < s2.length(); ++i){
            if(hash1 == hash2) return true;

            hash2[s2[i-k]-'a']--;
            hash2[s2[i] -'a']++;
        }

        return hash1 == hash2;
    }
};
