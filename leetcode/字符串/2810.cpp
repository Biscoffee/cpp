class Solution {
    public:
        string finalString(string s) {
            string p;
            for(char c : s){
                if(c == 'i'){
                    reverse(p.begin(), p.end());
                }else{
                    p += c;
                }
            }
            return p;
        }
    };