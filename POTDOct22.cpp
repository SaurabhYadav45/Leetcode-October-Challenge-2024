                                                           // Using MAX HEAP  + LEVEL ORDER TRAVERSAL
                                                           //          Method- 1

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*>q;
        priority_queue<long long>pq;
        q.push(root);
        q.push(NULL);
        long long sum = 0;

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front == NULL){
               pq.push(sum);
                sum = 0;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                sum += front->val;
                if(front->left != NULL){
                    q.push(front->left);
                }

                if(front->right != NULL){
                    q.push(front->right);
                }
            }
        }

        if(k > pq.size()){
            return -1;
        }

        for(int i=1; i<k; i++){
            pq.pop();
        }
        return pq.top();
    }
};


                                                           //          Method- 1
                                                           // Using vECTOR  + LEVEL ORDER TRAVERSAL
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*>q;
        vector<long long>temp;
        q.push(root);
        q.push(NULL);
        long long sum = 0;

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front == NULL){
                temp.push_back(sum);
                sum = 0;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                sum += front->val;
                if(front->left != NULL){
                    q.push(front->left);
                }

                if(front->right != NULL){
                    q.push(front->right);
                }
            }
        }

        if(k > temp.size()){
            return -1;
        }

        sort(temp.rbegin(), temp.rend());
        long result = temp[k-1];
        return result;
    }
};
