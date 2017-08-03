#include <iostream>
#include <map>
using namespace std;

/*****************************************************************
 * Find the length of the longest substring T of a given string (consists of lowercase letters only)
 * such that every character in T appears no less than k times.
 *
 * Example 1:
 * Input:
 * s = "aaabb", k = 3
 * Output:
 * 3
 * The longest substring is "aaa", as 'a' is repeated 3 times.
 *
 *
 * Example 2:
 * Input:
 * s = "ababbc", k = 2
 * Output:
 * 5
 * The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
 *
 *****************************************************************/
// start from 10:17
// 10:30，未编译版本, 结果未正确。耗时14min。大体正确，修改了几个小错误。
// 36开始, 用gdb调试，if (mCount[s[j]] < k)，错误写成if (mCount[j] < k)

class Solution {
public:
    int longestSubstring(string s, int k) {

        // 更周到的边界条件
        // if (s.size() == 0 || s.size() < k) return 0;
        // if (k==1) return s.size();

        if (s.size() < 1 || k == 0) {
            return s.size();
        }
        map<char, int> mCount;
        int j;
        for (j=0; j<s.size(); j++) {
            mCount[s[j]] += 1;
        }

        j = 0;
        while (j < s.size()) {
            if (mCount[s[j]] < k) {
                break;
            }
            ++j;
        }

        if (j == s.size()) {
            return s.size();
        }

        int m, n;
        m = longestSubstring(s.substr(0, j), k);
        n = longestSubstring(s.substr(j+1), k);

        return max(m ,n);
    }
};

// 灰灰：如果不使用map类型，用C语言的实现，可以用整数数组来存次数。题目中是lowercase only，所以，26个元素足矣。
// 而C++中的substr，可以使用strcpy和开始strncpy来实现。
// int count[256];
// memset(count , 0, sizeof(count));
// 
// //counting every char, s is string type
// for (char ch : s) {
//     count[ch]++;
// }

// int count[26] = {0};
// for (int j = first; j < last; ++j) ++count[s[j] - 'a'];

// mouse的实现无亮点，思路繁琐。但是这个split可以参考
// inline void split(const string &s, char delim, vector<string> &elems) {
//     stringstream ss;
//     ss.str(s);
//     string item;
//     while (getline(ss, item, delim)) {
//         cout << item << endl;
//         elems.push_back(item);
//     }
// }


int main(int argc, char* argv[]) {

    string input = "ababbc";
    int k = 2;
    int rst;

    // work
    // Solution *solu = new Solution;
    // rst = solu->longestSubstring(input, k);
    // delete solu;

    Solution solu;
    // rst = solu.longestSubstring(input, k);
    // cout << rst << endl;

    cout << solu.longestSubstring("ababbc", 2) << endl;
    cout << solu.longestSubstring("aaabb", 3) << endl;
    cout << solu.longestSubstring("", 3) << endl;
    cout << solu.longestSubstring("abc", 0) << endl;
    cout << solu.longestSubstring("abc", 1) << endl;
}
