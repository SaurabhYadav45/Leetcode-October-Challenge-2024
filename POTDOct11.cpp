
         // Optimal Approach Using Min heap
         // T.C = O(nlogn) 
         // S.C = O(n)

class Solution {
public:
    typedef pair<int, int> P;
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        
        int targetFriendArrivalTime = times[targetFriend][0];
        priority_queue<int, vector<int>, greater<int>>free;
        priority_queue<P, vector<P>, greater<P>>occupied;

        sort(times.begin(), times.end());
        int chairNo = 0;

        for(int i=0; i<n; i++){
            int arrival = times[i][0];
            int depart = times[i][1];

            while(!occupied.empty() && occupied.top().first <= arrival){
                free.push(occupied.top().second);
                occupied.pop();
            }

            if(free.empty()){
                occupied.push({depart, chairNo});
                if(arrival == targetFriendArrivalTime){
                    return chairNo;
                }
                chairNo++;
            }
            else{
                int leastAvailableChair = free.top();
                free.pop();
                if(arrival == targetFriendArrivalTime){
                    return leastAvailableChair;
                }

                occupied.push({depart, leastAvailableChair});
            }
        }
        return -1;
    }
};

                    // Brute Force
                    // T.C = O(n^2)
                    // S.C = O(n)

// class Solution {
// public:
//     int smallestChair(vector<vector<int>>& times, int targetFriend) {
//         int n = times.size();
//         vector<int>chair(n);

//         int targetFriendArrivalTime = times[targetFriend][0];

//         sort(times.begin(), times.end());

//         for(auto&time: times){
//             int arrival = time[0];
//             int depart = time[1];

//             for(int i=0; i<n; i++){
//                 if(chair[i]  <= arrival){
//                     chair[i] = depart;

//                     if(arrival == targetFriendArrivalTime){
//                         return i;
//                     }
//                     break;
//                 }
//             }
//         }
//         return -1;
//     }
// };
