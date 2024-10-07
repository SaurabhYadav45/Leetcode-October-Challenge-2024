class Solution {
public:
    int minLength(string s) {

                                          // Methjod-3 : Mre OPTIMIZED Solution
                                          // T.C = O(n)
                                          // S.C = O(1)
        int i=0; 
        int j=i+1;
        while(j < s.length()){
            if(i<0){
                i++;
                s[i] = s[j];
            }
            else if((s[j] == 'B' && s[i] == 'A')  || (s[j] == 'D' && s[i] == 'C')){
                i--;
            }
            else{
                i++;
                s[i] = s[j];
                
            }
            j++;
        }
        return i+1;


                                      // Optimized solution
                                      // T.C = O(n)
                                      // S.C = O(n) 
        // stack<char>st;
        // for(char&ch : s){
        //     if(st.empty()){
        //         st.push(ch);
        //         continue;
        //     }

        //     if(ch == 'B' && st.top() == 'A'){
        //         st.pop();
        //     }
        //     else if(ch == 'D' && st.top() == 'C'){
        //         st.pop();
        //     }
        //     else{
        //         st.push(ch);
        //     }
        // }
        // return st.size();

                            // BrUTE FORCE
                            // T.C = O(n^2)
                            // S.C = O(n^2)
        // while(s.find("AB") != -1 || s.find("CD") != -1){
        //     if(s.find("AB") != -1){
        //         s.erase(s.find("AB"), 2);
        //     }
        //     else if(s.find("CD") != -1){
        //         s.erase(s.find("CD"), 2);
        //     }
        // }
        // return s.length();
    }
};
