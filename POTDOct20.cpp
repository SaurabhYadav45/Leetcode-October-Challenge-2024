class Solution {
public:
    char solve(vector<char>&temp, char op){
        if(op == '!'){
            return temp[0] == 't' ? 'f' : 't';
        }

        if(op == '&'){
            for(char&ch : temp){
                if(ch == 'f'){
                    return 'f';
                }
            }
            return 't';
        }

        if(op == '|'){
            for(char&ch : temp){
                if(ch == 't'){
                    return 't';
                }
            }
            return 'f';
        }
        return true ; // never come to this line
    }
    bool parseBoolExpr(string expression) {
        stack<char>st;

        for(char&ch : expression){
            if(ch == ')'){
                vector<char>temp;
                while(st.top() != '('){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op = st.top();
                st.pop();
                st.push(solve(temp, op));
            }
            else{
                st.push(ch);
            }
        }
        return st.top() == 't' ? true : false;
    }
};
