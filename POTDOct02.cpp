class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // sort(arr.begin(), arr.end());

        set<int>st(arr.begin(), arr.end());
        unordered_map<int, int>mp;
        int i=1;
        for(auto& n : st){
            mp[n] = i;
            i++;
        }
        vector<int>result;
        for(int&num: arr){
            result.push_back(mp[num]);
        }
        return result;
    }
};
