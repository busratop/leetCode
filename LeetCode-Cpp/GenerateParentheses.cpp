class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    
    }

private:
    void backtrack(vector<string>& result, string current, int open, int close, int max) {
        // Eğer tüm parantezler yerleştirildiyse sonucu ekle
        if (current.length() == max * 2) {
            result.push_back(current);
            return;
        }

        // Açma parantezi ekleyebiliriz
        if (open < max) {
            backtrack(result, current + "(", open + 1, close, max);
        }

        // Kapama parantezi ekleyebiliriz (sadece açık sayısı kadar)
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, max);
        }

    }
    
};
