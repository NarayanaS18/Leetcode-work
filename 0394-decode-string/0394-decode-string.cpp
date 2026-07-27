class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        int curNum = 0;
        string curStr = "";

        for(char ch : s){
            if(isdigit(ch)){
                curNum = curNum*10 + (ch-'0');
            }
            else if(ch == '['){
                numStack.push(curNum);
                strStack.push(curStr);
                curNum = 0;
                curStr = "";
            }
            else if(ch == ']'){
                string prevStr = strStack.top();
                strStack.pop();

                int count = numStack.top();
                numStack.pop();

                string repeated = "";
                while(count != 0){
                    repeated += curStr;
                    count--;
                }
                curStr = prevStr + repeated;
            }
            else{
                curStr += ch;
            }
        }
        return curStr;
    }
};