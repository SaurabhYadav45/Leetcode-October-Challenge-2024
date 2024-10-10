                                               // Optimal Solution : two Pointer
                                               // T.C = O(n)
                                               // S.C = O(n)

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int ramp = 0;
        vector<int>maxElement(n);
        maxElement[n-1] = nums[n-1];

        for(int i=n-2; i>=0; i--){
            maxElement[i] = max(maxElement[i+1], nums[i]);
        }

        int i=0; 
        int j=0;
        while(j < n){
            while(i < j && nums[i] > maxElement[j]){
                i++;
            }
            ramp = max(ramp, j-i);
            j++;
        }
        return ramp;
    }
};

                                                 // BETTER APPROACH
                                                 // T.C = O(n^2)
                                                 // S.C = O(1)


// class Solution {
// public:
//     int maxWidthRamp(vector<int>& nums) {
//         int n = nums.size();
//         int ramp = 0;
//         for(int i=0; i<n; i++){
//             for(int j=n-1; j>i;j--){
//                 if(nums[i] <= nums[j]){
//                     int w = j - i;
//                     ramp = max(ramp, w);
//                     break;
//                 }
//             }
//         }
//         return ramp;
//     }
// };

                                                   // BRUTE FORCE
                                                   // T.C = O(n^2)
                                                   // S.C = O(1)

// class Solution {
// public:
//     int maxWidthRamp(vector<int>& nums) {
//         int n = nums.size();
//         int ramp = 0;
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n;j++){
//                 if(nums[i] <= nums[j]){
//                     int w = j - i;
//                     ramp = max(ramp, w);
//                 }
//             }
//         }
//         return ramp;
//     }
// };
