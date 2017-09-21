#include <iostream>
#include <map>
#include <vector>
using namespace std;

/****************************************************************
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
 * determine if the input string is valid.
 *
 * The brackets must close in the correct order,
 * "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 ****************************************************************/

class Solution {
public:
    bool isValid(string s) {
        map<char, char> parenttheses;
        vector<char> right;

        parenttheses.insert(pair<char, char>('(', ')'));
        parenttheses.insert(pair<char, char>('{', '}'));
        parenttheses.insert(pair<char, char>('[', ']'));

        int i;
        for (i = 0; i < s.size(); i++) {
            if (parenttheses.find(s[i]) != parenttheses.end()) {
                right.push_back(parenttheses[s[i]]);
                continue; // 一开始忘了加 continue
            }

            if (right.size() < 1 || right.back() != s[i]) {
                return false;
            }
            right.pop_back();
        }

        if (right.size() > 0)
            return false;

        return true;
    }
};

// 解法的另一个思路
// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> paren;
//         for (char& c : s) {
//             switch (c) {
//                 case '(': 
//                 case '{': 
//                 case '[': paren.push(c); break;
//                 case ')': if (paren.empty() || paren.top()!='(') return false; else paren.pop(); break;
//                 case '}': if (paren.empty() || paren.top()!='{') return false; else paren.pop(); break;
//                 case ']': if (paren.empty() || paren.top()!='[') return false; else paren.pop(); break;
//                 default: ; // pass
//             }
//         }
//         return paren.empty() ;
//     }
// };

int main(int argc, char* argv[]) {
    Solution solu; 
    string str = "()[]";
    cout << str << ": " << solu.isValid(str) << endl;
    str = "{[]}";
    cout << str << ": " << solu.isValid(str) << endl;
    str = "{}[]()";
    cout << str << ": " << solu.isValid(str) << endl;

    str = "([)]";
    cout << str << ": " << solu.isValid(str) << endl;
    str = "[";
    cout << str << ": " << solu.isValid(str) << endl;
}
