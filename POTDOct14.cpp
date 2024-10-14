class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long>pq;
        for(auto&num: nums){
            pq.push(num);
        }

        long long score = 0;
        for(int i=0; i<k;i++){
            double temp = pq.top();
            score += temp;
            pq.pop();
            pq.push(ceil(temp/ 3));
        }
        return score;
    }
};
