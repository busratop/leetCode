class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        vector<string> stack;
        string token, result;

        // Split the path by '/'
        while (getline(ss, token, '/')) {
            // Ignore empty strings and '.'
            if (token == "" || token == ".") {
                continue;
            }
            // Handle '..' by popping the last directory if stack is not empty
            else if (token == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            }
            // Otherwise, push valid directory names to the stack
            else {
                stack.push_back(token);
            }
        }

        // Construct the simplified canonical path
        for (string dir : stack) {
            result += "/" + dir;
        }

        // If the result is empty, return '/'
        if (result.empty()) {
            return "/";
        }
        
        return result;
    }
};
