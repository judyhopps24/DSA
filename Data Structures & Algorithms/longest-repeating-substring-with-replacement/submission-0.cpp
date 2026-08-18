class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int r=0, l=0;
        int output =0;
        while(r<s.length()){
            // cout<<l<<" "<<r<<'\n';
            char c = s[r];
            freq[c - 'A']++;
            // for(auto x: freq)
            //     cout<<x<<" ";
            // cout<<"\n";

            int maxFreq =0;
            for(int i=0;i<26;i++){
                maxFreq = max(maxFreq, freq[i]);
            }
            // cout<<"maxFreq: " <<maxFreq<<'\n';

            if(maxFreq >= r-l+1 - k  ){
                // cout<<"can accom : so new length: "<< r-l+1 <<"\n";
                output= max(output, r-l+1 );
            }else{
                // cout<<"cant accom. forwarding. l: \n";
                freq[s[l] -'A']--;
                l++;
            }
            r++;
        }
        return output; 
    }
};
