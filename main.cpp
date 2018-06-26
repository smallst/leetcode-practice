class Solution {
public:
    void reverseWords(string &s) {
        int l = s.length();
        for(int i = 0; i <l/2; i++)
        {
            char temp = s[i];
            s[i] = s[l-1-i];
            s[l-1-i] = temp;
        }
        int st = 0;
        for(int i = 0; i !=l; i++)
        {
            if(s[i] == ' ')
            {
                for(int j = st; j < (i+st)/2; j++)
                {
                    char temp = s[j];
                    s[j] = s[i-1-(j-st)];
                    s[i-1-(j-st)] = temp;
                }
                st = i+1;
            }
        }
        for(int j = st; j < (l+st)/2; j++)
        {
            char temp = s[j];
            s[j] = s[l-1-(j-st)];
            s[l-1-(j-st)] = temp;
        }
        while(s[0] == ' ')
        {
            s = s.substr(1,s.length());
        }
        l = s.length();
        while(s[l-1] == ' ')
        {
            s= s.substr(0,l -1);
            l --;
        }
        l = s.length();
        for(int i = 1; i <l; i++)
        {
            if(s[i] == ' ' && s[i-1] == ' ')
            {
                s.erase(i, 1);
                i -- ;
                l --;
            }
        }
    }
};