class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int counts[256] = {0};

        for (int i = 0; i < s1.length(); i++) {
            int offset = (i & 1) << 7;
            counts[offset + s1[i]]++;
            counts[offset + s2[i]]--;
        }

        for (int i = 0; i < 256; i++) {
            if (counts[i] != 0) {
                return false;
            }
        }

        return true;
    }
};