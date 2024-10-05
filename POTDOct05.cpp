class Solution {
public:
    
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        
        vector<int>s1_freq(26, 0);
        vector<int>s2_freq(26, 0);

        sort(s1.begin(), s1.end());

        for(char& ch : s1){
            s1_freq[ch - 'a']++;
        }
        int i=0;
        int j=0;
        while(j < m){
            s2_freq[s2[j] - 'a']++;

            if(j-i+1 > n){
                s2_freq[s2[i] - 'a']--;
                i++;
            }
            if(s2_freq == s1_freq){
                return true;
            }
            j++;
        }
        return false;
    }
};

                        // brute force -2

// class Solution {
// public:
    
//     bool checkInclusion(string s1, string s2) {
//         sort(s1.begin(), s1.end());
//         int l  = s1.length();
//         for(int i=0; i<s2.length(); i++){
//             string s = s2.substr(i, l);
//             sort(s.begin(), s.end());
//             if(s == s1){
//                 return true;
//             }
//         }
//         return false;
//     }
// };


                          // B R U T E     F O R C E

// class Solution {
// public:
//     void permuteRec(string& s, int idx, vector<string>&permutation){
//         // Base case
//         if (idx == s.size() - 1) {
//             permutation.push_back(s);
//             return;
//         }

//         for (int i = idx; i < s.size(); i++) {
        
//             // Swapping 
//             swap(s[idx], s[i]);

//             // First idx+1 characters fixed
//             permuteRec(s, idx + 1, permutation);

//             // Backtrack
//             swap(s[idx], s[i]);
//         }
//     }
    
//     bool checkInclusion(string s1, string s2) {
//         vector<string>permutation;
//         permuteRec(s1, 0, permutation);

//         for(auto& s : permutation){
//             size_t found = s2.find(s);
//             if (found != string::npos){
//                 return true;;
//             }
//         }
//         return false;
//     }
// };
