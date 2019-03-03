class Solution {
public:
    unordered_map<long, int> dict;
    string fractionToDecimal(int numerato, int denominato) {
        
        long numerator= numerato, denominator =denominato;
        bool flag = true;
        if(numerator < 0 && denominator >= 0)
        {
            flag =false;
        }
        if(numerator >= 0 && denominator < 0)
        {
            flag =false;
        }
                numerator = numerator < 0 ? -numerator:numerator;
        denominator = denominator < 0 ? -denominator:denominator;

        int index = 1;
        long orig = numerator % denominator;
        long iii = numerator / denominator;
        if(!orig)
                return iii == 0 ? to_string(iii) : ((flag?"":"-") + to_string(iii));

        else
        dict[orig] = index++;
        long temp = orig * 10 % denominator;
        string repeat = to_string(orig*10/denominator);
        while(temp && dict[temp]== 0)
        {
            dict[temp] = index ++;
            repeat += to_string(temp * 10 / denominator);
            temp = temp* 10 % denominator;
        }
        if(temp && dict[temp] != 0)
        {
            return (flag?"":"-") + to_string(iii) + "." + repeat.substr(0, dict[temp]-1) + "(" + repeat.substr(dict[temp]-1, repeat.length()) + ")";
        }
        
        return (flag?"":"-") + to_string(iii) + "." + repeat;
}
};
