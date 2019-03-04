class Solution {
public:
    map<char, vector<char>> d2s;
    vector<string> letterCombinations(string digits) {
        char c, i;
        for(c = 'a', i = '2'; c < 'y'; i++)
        {
            d2s[i].push_back(c++);
            d2s[i].push_back(c++);
            d2s[i].push_back(c++);
            if(i == '7')
                d2s[i].push_back(c++);
        }
        d2s['9'].push_back('z');
        
        vector<string> res;
        if(digits.size() == 0)
            return res;
        mapDS(res, digits, "");
        return res;
    }
    void mapDS(vector<string>& res, string digits, string str){
        int l = digits.size();
        if(l == 0)
        {
            res.push_back(str);
            return;
        }
        vector<char> temp = d2s[digits[0]];
        for(auto i = temp.begin();i != temp.end(); i++)
        {
            mapDS(res, digits.substr(1, l-1), str + (*i));
        }
    }
};
