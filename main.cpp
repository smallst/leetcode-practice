class Solution {
public:
   
    void generateTail(vector<string>& v, string s, int n, int m){
    if(n == 0 && m == 0)
    {
        v.push_back(s);
        return;
    }
    if(m > 0) generateTail(v, s+")", n, m-1);
    if(n > 0) generateTail(v, s+"(", n-1, m+1);
}
vector<string> generateParenthesis(int n) {
    std::vector<string> res;
    if(n == 0)
    return res;
    generateTail(res, "", n, 0);
    return res;
}



};
