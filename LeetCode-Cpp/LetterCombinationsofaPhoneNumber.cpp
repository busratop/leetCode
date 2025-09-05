class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> result;
        string current;
        vector<string> phoneMap = {
            "",     "",     "abc",  // 0, 1, 2
            "def",  "ghi",  "jkl",  // 3, 4, 5
            "mno",  "pqrs", "tuv",  // 6, 7, 8
            "wxyz"             // 9
        };

        backtrack(digits, 0, current, result, phoneMap);
        return result;
    }

private:
    void backtrack(const string& digits, int index, string& current,
                   vector<string>& result, const vector<string>& phoneMap) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        string letters = phoneMap[digits[index] - '0'];
        for (char letter : letters) {
            current.push_back(letter);
            backtrack(digits, index + 1, current, result, phoneMap);
            current.pop_back(); // geri izleme
        }
    }
};
