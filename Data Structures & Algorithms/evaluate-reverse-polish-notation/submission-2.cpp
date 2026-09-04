class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> numbers;

        for (string& token : tokens) {
            // it could be a negative number; for all these cases the last digit must be a digit, the first maybe '-'
            // so we check the last
            if (isdigit(token.back())) {
                numbers.push_back(stoi(token));
            }
            else {
                int newVal = evaluate(numbers, token[0]);
                numbers.pop_back();
                numbers.pop_back();
                numbers.push_back(newVal);
            }
        }

        return numbers.front();
    }

private:
    int evaluate(vector<int>& numbers, char operand) {
        int result;
        switch (operand) {
            case '+':
                result = numbers[numbers.size() - 2] + numbers.back();
                break; 
            case '-':
                result = numbers[numbers.size() - 2] - numbers.back();
                break; 
            case '*':
                result = numbers[numbers.size() - 2] * numbers.back();
                break;                 
            case '/':
                result = numbers[numbers.size() - 2] / numbers.back();
                break; 
        }

        return result;
    }
};
