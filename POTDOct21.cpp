class Solution {
public:
    void solve(string& s, int i, int currCount, int& maxCount, unordered_set<string>&st){
        if(i >= s.length()){
            maxCount = max(maxCount, currCount);
            return;
        }

        for(int j=i; j<s.length(); j++){
            string sub = s.substr(i, j-i+1);
            if(st.find(sub) == st.end()){
                st.insert(sub);
                solve(s, j+1, currCount+1, maxCount, st);
                st.erase(sub);
            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string>st;
        int currCount = 0;
        int maxCount = 0;
        int i=0;

        solve(s, i, currCount, maxCount, st);

        return maxCount;
    }
};
