class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0)
            return false;
        if (s == "")
            return true;
        stack<char> str;
        char arr[127];
        arr[')' + 0] = '(' + 0;
        arr[']' + 0] = '[' + 0;
        arr['}' + 0] = '{' + 0;
        
        for (int i = 0; i < s.size(); i ++){
            char temp = s[i];
            if (temp == ')' || temp == ']' || temp == '}'){
                if (str.empty())
                    return false;
                char a = str.top();
                str.pop();
                if (arr[temp + 0] != a)
                    return false;
            }
            else
                str.push(temp);
            
        }
        if (str.empty())
            return true;
        return false;
        
    }
};