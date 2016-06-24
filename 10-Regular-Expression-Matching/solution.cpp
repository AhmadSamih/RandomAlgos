class Solution {
public:
    bool helper(string s, int si, string p, int pi){
    
        if(si == s.size() && pi == p.size()) return true;

        if(p[pi+1] == '*'){
            return helper(s,si,p,pi+2) || ((s[si]==p[pi] || p[pi]=='.') && si<s.size() && helper(s,si+1,p,pi));
        }else{
            return (si<s.size() && (s[si]==p[pi] || p[pi]=='.')) && helper(s, si+1, p, pi+1);
        }
    }
    
    bool isMatch(string s, string p) {
        return helper(s,0,p,0);
    }
};