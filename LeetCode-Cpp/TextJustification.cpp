class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
         vector<string> result;
        vector<string> currentLine;
        int currentLength = 0;

        for (const string& word : words) {
            if (currentLength + word.length() + currentLine.size() > maxWidth) {
                result.push_back(justifyLine(currentLine, maxWidth, false));
                currentLine.clear();
                currentLength = 0;
            }

            currentLine.push_back(word);
            currentLength += word.length();
        }

        // Justify the last line (left-justified)
        result.push_back(justifyLine(currentLine, maxWidth, true));

        return result;
    }
    string justifyLine(const vector<string>& words, int maxWidth, bool isLastLine) {
    if (isLastLine || words.size() == 1) {
        string line = words[0];
        for (int i = 1; i < words.size(); ++i) {
            line += ' ' + words[i];
        }
        line += string(maxWidth - line.length(), ' ');
        return line;
    } else {
        int totalSpaces = maxWidth - accumulate(words.begin(), words.end(), 0, [](int sum, const string& word) { return sum + word.length(); });
        int numGaps = words.size() - 1;
        int spacesBetweenWords = totalSpaces / numGaps;
        int extraSpaces = totalSpaces % numGaps;

        string justifiedLine = words[0];
        for (int i = 1; i < words.size(); ++i) {
            int spaces = spacesBetweenWords + (i <= extraSpaces ? 1 : 0);
            justifiedLine += string(spaces, ' ') + words[i];
        }

        return justifiedLine;
    }
}
};
