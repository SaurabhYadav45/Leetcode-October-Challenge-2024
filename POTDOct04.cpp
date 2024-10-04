class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end());
        
        int start = 0;
        int end = n-1;
        long long sum = skill[start] + skill[end];
        while(start < end){
            if(skill[start] + skill[end] != sum){
                return -1;
            }
            start++;
            end--;
        }

        long long chemistry = 0;
        start = 0;
        end = n-1;
        while(start < end){
            chemistry += skill[start] * skill[end];
            start++;
            end--;
        }
        return chemistry;
    }
};
