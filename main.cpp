class Solution {
public:
    bool isValidSerialization(string preorder) {
        int count = 0;
        int l = preorder.length();
        if(preorder[l-1] != '#')
            return false;
        for(int i = 0; i< l-1; i++)
        {
            if(preorder[i] == '#')
            {
                count --;
                if(i<l-1){i++;}
            }
                else
                {
                    count ++;
                    while(i<l-1&&preorder[++i] !=',');
                }
            if(count < 0 )
                return false;
        }
        if(count == 0)
            return true;
        return false;
    }
};
