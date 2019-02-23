class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        bool valid = true;
        for(int i = 0; valid && i< s.length(); i++)
        {
            switch(s[i])
            {
                case '(': 
                case '[': 
                case '{': st.push(s[i]); break;
                case ')': if(st.empty() || st.top() != '(') {
                    valid = false;
                    break;
                }
                    else st.pop();
                    break;
                          case ']':if(st.empty() || st.top() != '[') {

                    valid = false;
                    break;
                }
                    else st.pop();
                    break;
                            case '}': if(st.empty() || st.top() != '{') {

                    valid = false;
                    break;
                }
                    else st.pop();
                    break;
            }
       
        }
                if(!st.empty())
        valid = false;

        return valid;
    }
};