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
// 10:30��δ����汾, ���δ��ȷ����ʱ14min��������ȷ���޸��˼���С����
// 36��ʼ, ��gdb���ԣ�if (mCount[s[j]] < k)������д��if (mCount[j] < k)

class Solution {
public:
    int longestSubstring(string s, int k) {

        // ���ܵ��ı߽�����
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

// �һң������ʹ��map���ͣ���C���Ե�ʵ�֣��������������������������Ŀ����lowercase only�����ԣ�26��Ԫ�����ӡ�
// ��C++�е�substr������ʹ��strcpy�Ϳ�ʼstrncpy��ʵ�֡�
// int count[256];
// memset(count , 0, sizeof(count));
// 
// //counting every char, s is string type
// for (char ch : s) {
//     count[ch]++;
// }

// int count[26] = {0};
// for (int j = first; j < last; ++j) ++count[s[j] - 'a'];

// mouse��ʵ�������㣬˼·�������������split���Բο�
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
