class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();
        vector<int>maxRight(n);

        maxRight[n-1] = n-1;
        for(int i=n-2; i>=0;i--){
            int maxRightIdx = maxRight[i+1];
            int maxRightElement = s[maxRightIdx];
            maxRight[i] = (s[i] > maxRightElement) ? i : maxRightIdx;
        }

        for(int i=0; i<n; i++){
            int maxRightIdx = maxRight[i];
            int maxRightElement = s[maxRightIdx];
            if(s[i] < maxRightElement){
                swap(s[i], s[maxRightIdx]);
                return stoi(s);
            }
        }
        return num;
    }
};
