class Solution {
public:
    string invert(string s){
        for(int i=0; i<s.length();i++){
            if(s[i] == '0'){
                s[i] = '1';
            }
            else{
                s[i] = '0';
            }
        }
        return s;
    }

    string reverseString(string&s){
        reverse(s.begin(), s.end());
        return s;
    }

    char findKthBit(int n, int k) {

        string s = "0";
        for(int i=1; i<n; i++){
           string temp = invert(s);
           s = s + "1" + reverseString(temp);
        }

        char ch = s[k-1];
        return ch;
    }
};
