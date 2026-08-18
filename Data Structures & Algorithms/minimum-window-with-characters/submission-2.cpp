class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) return "";

        unordered_map<char, int> freq;
        for (char c : t) freq[c]++;

        unordered_map<char, int> windowFreq;
        int numOfLettersMatched = 0; // Fixed uninitialized bug
        
        // Instead of heavy s.substr(), we track indices
        int minLen = INT_MAX;
        int startIdx = 0;

        int l = 0, r = 0;
        while (r < s.size()) {
            
            // ==========================================
            // STEP 1: Introduce Incoming Element (Right)
            // ==========================================
            char rightChar = s[r];
            if (freq.find(rightChar) != freq.end()) {
                windowFreq[rightChar]++;
                if (windowFreq[rightChar] == freq[rightChar]) {
                    numOfLettersMatched++;
                }
            }

            // ==========================================
            // STEP 2: Assess Window Validity
            // ==========================================
            while (numOfLettersMatched == freq.size()) {
                
                // ==========================================
                // STEP 3: Record Answer (At its tightest)
                // ==========================================
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startIdx = l;
                }

                // ==========================================
                // STEP 4: Evict Outgoing Element (Left)
                // ==========================================
                char leftChar = s[l];
                if (freq.find(leftChar) != freq.end()) {
                    if (windowFreq[leftChar] == freq[leftChar]) {
                        numOfLettersMatched--;
                    }
                    windowFreq[leftChar]--;
                }
                l++; // Shrink left pointer
            }

            r++; // Expand right pointer (Always at the very end)
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};
