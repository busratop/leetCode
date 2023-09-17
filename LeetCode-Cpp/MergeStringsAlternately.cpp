#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
         std::string merged;
    size_t length = std::max(word1.length(), word2.length());

    for (size_t i = 0; i < length; ++i) {
        if (i < word1.length()) {
            merged += word1[i];
        }
        if (i < word2.length()) {
            merged += word2[i];
        }
    }

    return merged;
    }
   
};

//int main(int argc, char **argv)
//{
//    Solution solution;
  //  cout << solution.mergeAlternately("abcdc", "pqrolm");
    //return 0;
//}
