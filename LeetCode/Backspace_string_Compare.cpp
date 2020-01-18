class Solution {
public:
    bool backspaceCompare(string S, string T) {
        if (S == T && S == "")
            return true;
        stack<char> str1, str2;
        for (int i = 0; i < S.size(); i++){
            if (S[i] != '#')
                str1.push(S[i]);
            else if (!str1.empty() && S[i] == '#')
                str1.pop();
        }
        
        for (int i = 0; i < T.size(); i++){
            if (T[i] != '#')
                str2.push(T[i]);
            else if (!str2.empty() && T[i] == '#')
                str2.pop();
        }
        if (str1.size() == str2.size()){
            while (!str1.empty()){
                if (str1.top() != str2.top())
                    return false;
                str1.pop();
                str2.pop();
            }
        }
        else
            return false;
        return true;
    }
};