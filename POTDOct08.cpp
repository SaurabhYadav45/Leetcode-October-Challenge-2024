class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        for(char&ch: s){
            if(!st.empty() && ch == ']' && st.top() == '['){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }

        int no_of_opening_bracket = st.size()/2;
        return (no_of_opening_bracket + 1)/2;
    }
};
