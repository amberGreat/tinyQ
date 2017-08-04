#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>
using namespace std;

/***************************************************************
 * Design a data structure that supports all following operations in average O(1) time.
 * 
 * insert(val): Inserts an item val to the set if not already present.
 * remove(val): Removes an item val from the set if present.
 * getRandom: Returns a random element from current set of elements.
 * Each element must have the same probability of being returned.
 * 
 * Example:
 * // Init an empty set.
 * RandomizedSet randomSet = new RandomizedSet();
 * 
 * // Inserts 1 to the set. Returns true as 1 was inserted successfully.
 * randomSet.insert(1);
 * 
 * // Returns false as 2 does not exist in the set.
 * randomSet.remove(2);
 * 
 * // Inserts 2 to the set, returns true. Set now contains [1,2].
 * randomSet.insert(2);
 * 
 * // getRandom should return either 1 or 2 randomly.
 * randomSet.getRandom();
 * 
 * // Removes 1 from the set, returns true. Set now contains [2].
 * randomSet.remove(1);
 * 
 * // 2 was already in the set, so return false.
 * randomSet.insert(2);
 * 
 * // Since 2 is the only number in the set, getRandom always return 2.
 * randomSet.getRandom();
***************************************************************/

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mm.find(val) != mm.end()) {
            return false;
        }
        vv.push_back(val);
        mm[val] = vv.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mm.find(val) == mm.end()) {
            return false;
        }

        // int back = vv.pop_back();
        int bb = vv.back();
        vv[mm[val]] = bb;
        mm[bb] = mm[val]; // 一开始忘了更新mm，代码错误，shit
        vv.pop_back();
        mm.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return vv[rand() % vv.size()];
    }

private:
    // 看看跟unorder的区别，为什么总要unorder
    map<int, int> mm;
    vector<int> vv;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

// 6:45, 中途可能吃饭去
// 9:31开始写，9:42开始调试，9：46能运行。
int main(int argc, char* argv[]) {

    // maybe need pointer
    // RandomizedSet obj = new RandomizedSet();
    RandomizedSet obj;
    // bool param_1 = obj.insert(2);
    // bool param_2 = obj.remove(5);
    // int param_3 = obj.getRandom();

    // cout << param_1 << endl;
    // cout << param_2 << endl;
    // cout << param_3 << endl;

    // ["RandomizedSet","insert","insert","remove","insert","remove","getRandom"]
    // [[],[0],[1],[0],[2],[1],[]]

    // Output:
    // [null,true,true,true,true,true,1]
    // Expected:
    // [null,true,true,true,true,true,2]

    cout << "insert 0: " << obj.insert(0) << endl;;
    cout << "insert 1: " << obj.insert(1) << endl;;
    cout << "remove 0: " << obj.remove(0) << endl;;
    cout << "insert 2: " << obj.insert(2) << endl;;

    cout << "remove 1: " << obj.remove(1) << endl;;
    // cout << "remove 3: " << obj.remove(3) << endl;;

    cout << "getRandom: " << obj.getRandom() << endl;;
    // cout << "getRandom: " << obj.getRandom() << endl;;
    // cout << "getRandom: " << obj.getRandom() << endl;;
}
