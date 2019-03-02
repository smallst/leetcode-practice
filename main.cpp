class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> wm;
        for(auto i = words.begin(); i != words.end(); i++)
        {
            int x = 0;
            for(auto c = 0; c < (*i).length(); c++)
            {
                x |= 1<<((*i)[c] - 'a');
            }
            wm.push_back(x);
        }
        int l = wm.size();
        int max = 0;
        for(int i = 0; i < l; i++)
        {
            for(int j = i+1; j < l; j++)
            {
                if(!(wm[i] & wm[j]))
                {
                    int length = words[i].length() * words[j].length();
                    max = max > length ? max : length;
                }
            }
        }
        return max;
    }
};
