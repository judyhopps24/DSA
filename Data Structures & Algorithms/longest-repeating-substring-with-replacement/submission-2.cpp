class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int r = 0, l = 0;
        int output = 0;
        int maxFreq = 0; // We can track this globally to be more efficient

        while (r < s.length()) {
            // STEP 1: Introduce incoming element
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            // STEP 2 & 4: Shrink until the window is valid
            // A window is INVALID if: (Total characters - Most frequent character > k)
            while ((r - l + 1) - maxFreq > k) {
                freq[s[l] - 'A']--;
                l++; // Shrink left
            }

            // STEP 3: Record answer
            // Because the while loop above guarantees the window is now valid,
            // we can confidently update our maximum output.
            output = max(output, r - l + 1);

            // Expand right pointer (Always at the very end)
            r++;
        }
        return output; 
    }
};