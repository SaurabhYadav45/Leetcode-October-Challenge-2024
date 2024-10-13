class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        //{element, listIdx, idx} //vector<int>{a, b, c}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        int maxEl = INT_MIN;
        for(int i = 0; i < k; i++) {
            pq.push({nums[i][0], i, 0});
            maxEl = max(maxEl, nums[i][0]);
        }

        vector<int> resultRange = {-1000000, 1000000};

        while(!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();

            int minEl = curr[0];
            int listIdx = curr[1];
            int idx     = curr[2];

            if(maxEl - minEl < resultRange[1] -  resultRange[0]) {
                resultRange[0] = minEl;
                resultRange[1] = maxEl;
            }

            //decrease the rangen fro minimums ide
            if(idx+1 < nums[listIdx].size()) {
                int nextElement = nums[listIdx][idx+1];
                pq.push({nextElement, listIdx, idx+1});
                maxEl = max(maxEl, nextElement);
            } else {
                break;
            }
        }

        return resultRange;
    }
};

// class Solution {
// public:
//     vector<int> smallestRange(vector<vector<int>>& nums) {
//         int k = nums.size();

//         vector<int> vec(k, 0); //{0, 0, 0....}

//         vector<int> resultRange = {-1000000, 1000000}; //(a, b)

//         while(true) {
//             int minEl        = INT_MAX;
//             int maxEl        = INT_MIN;
//             int minElListIdx = 0;

//             for(int i = 0; i < k; i++) {
//                 int listIdx = i;
//                 int elIdx = vec[i];
//                 int element = nums[listIdx][elIdx];

//                 if(element < minEl) {
//                     minEl = element;
//                     minElListIdx = listIdx;
//                 }

//                 maxEl = max(maxEl, element);
//             }

//             //raneg (minEl, maxEl)
//             if(maxEl - minEl < resultRange[1] - resultRange[0]) {
//                 resultRange[0] = minEl;
//                 resultRange[1] = maxEl;
//             }

//             //now shorten this range by moving minElement idx
//             int nextIndex = vec[minElListIdx]+1;
//             if(nextIndex >= nums[minElListIdx].size()) {
//                 break;
//             }
//             vec[minElListIdx] = nextIndex;
//         }

//         return resultRange;
//     }
// };

// class Info{
//     public:
//     int data;
//     int rowIndex;
//     int colIndex;

//     Info(int value, int row, int col){
//         this->data = value;
//         this->rowIndex = row;
//         this->colIndex = col;
//     }
// };

// class compare{
//     public:
//     bool operator()(Info*a, Info*b){
//         return a->data > b->data;
//     }
// };

// class Solution {
// public:
//     vector<int> smallestRange(vector<vector<int>>& nums) {
        
//         priority_queue<Info*, vector<Info*>, compare> pq;
//         int maxi = INT_MIN;
//         int mini = INT_MAX;

//         //process first k elements ko 
//         for(int i=0; i<nums.size(); i++) {
//             int element = nums[i][0];
//             int row = i;
//             int col = 0;
//             Info* temp = new Info(element, row, col);
//             pq.push(temp);
//             maxi = max(maxi, element);
//             mini = min(mini,element);
//         }

//         int miniAns = mini;
//         int maxiAns = maxi;

//         while(!pq.empty()) {
//             Info* topNode = pq.top();
//             int topData = topNode->data;
//             int topCol = topNode->colIndex;
//             int topRow = topNode->rowIndex;

//             pq.pop();

//             mini = topNode->data;
//             //maxi ki value pehle se padi hui h 
//             //compare krlete h for smaller range
//             if((maxi-mini) < (maxiAns - miniAns)) {
//                 //update ans;
//                 miniAns  = mini;
//                 maxiAns = maxi;
//             }

//             //insertion wala step
//             if(topCol + 1 < nums[topRow].size()) {
//                 int newElement = nums[topRow][topCol+1];
//                 maxi = max(maxi, newElement);
//                 Info* newInfo = new Info(newElement, topRow, topCol+1);
//                 pq.push(newInfo);
//             }
//             else {
//                 //aggge koi element nahi h push krne ko
//                 break;
//             }


//         }
//         vector<int> ans;
//         ans.push_back(miniAns);
//         ans.push_back(maxiAns);
//         return ans;
//     }
// };
