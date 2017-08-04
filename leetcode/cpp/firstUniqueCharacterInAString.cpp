#include <iostream>
#include <map>

using namespace std;

/***************************************************************************************
 *
 * Given a string, find the first non-repeating character in it and return it's index.
 * If it doesn't exist, return -1.
 *
 * Examples:
 *
 * s = "leetcode"
 * return 0.
 *
 * s = "loveleetcode",
 * return 2.
 *
 * Note: You may assume the string contain only lowercase letters.
 ***************************************************************************************/

class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> mCount;
        int i;
        for (i=0; i<s.size(); ++i) {
            mCount[s[i]] += 1;
        }

        for (i=0; i<s.size(); ++i) {
            if (mCount[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};

// 6:16开始, 6:20完成。结果正确

int main(int argc, char* argv[]) {

    string s = "leetcode";
    Solution solu;
    cout << s << ": " << solu.firstUniqChar(s) << endl;
    s = "loveleetcode";
    cout << s << ": " << solu.firstUniqChar(s) << endl;
    return 0;
}
