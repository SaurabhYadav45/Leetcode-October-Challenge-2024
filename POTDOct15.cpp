class Solution {
public:
    long long minimumSteps(string s) {
        long long count = 0;
        long long swap = 0; 

        for(auto& ch: s){
            if(ch == '1'){
                count++;
            }
            else{
                swap += count;
            }
        } 
        return swap;
    }
};
