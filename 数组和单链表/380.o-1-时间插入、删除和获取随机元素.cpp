/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

// @lc code=start
class RandomizedSet {
public:
    // 存储当前的数组
    vector<int> nums;
    // 保存对应元素到索引的hash
    unordered_map<int, int> ValToIndex;
    RandomizedSet() {

    }
    
    bool insert(int val) {
        // 如果不存在val
        if (ValToIndex.count(val) == 0) {
            nums.push_back(val);
            ValToIndex[val] = nums.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        // 如果存在val
        if (ValToIndex.count(val)) {
            int index = ValToIndex[val];
            int num = nums.back();
            // 将数组尾部的元素移到需要删除元素的位置
            ValToIndex[num] = index;
            nums[index] = num;
            // 将数组尾部的元素删除
            nums.pop_back();
            ValToIndex.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

