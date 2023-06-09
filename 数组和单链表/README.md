## 数组/单链表系列算法

### 链表

#### 双指针

|                             题目                             | 难度 |                 题解                 |
| :----------------------------------------------------------: | :--: | :----------------------------------: |
| [21.合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/) | 简单 |                                      |
| [876. 链表的中间结点](https://leetcode.cn/problems/middle-of-the-linked-list/) | 简单 |               快慢指针               |
| [19. 删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/) | 中等 |               快慢指针               |
| [141. 环形链表](https://leetcode.cn/problems/linked-list-cycle/) | 简单 |               快慢指针               |
| [142. 环形链表 II](https://leetcode.cn/problems/linked-list-cycle-ii/) | 中等 |                                      |
| [870. 优势洗牌](https://leetcode.cn/problems/advantage-shuffle/) | 中等 | 总结文档**[田忌赛马背后的算法决策]** |

#### 递归—反转链表

|                             题目                             | 难度 |            题解             |
| :----------------------------------------------------------: | :--: | :-------------------------: |
| [206. 反转链表](https://leetcode.cn/problems/reverse-linked-list/) | 简单 |       递归/非递归 206       |
| [92. 反转链表 II](https://leetcode.cn/problems/reverse-linked-list-ii/) | 中等 | 递归，基于反转前N个节点链表 |
| [25. K 个一组翻转链表](https://leetcode.cn/problems/reverse-nodes-in-k-group/) | 困难 |                             |

##### 206 反转链表，递归算法

对于一个初始的链表：1->2->3->4->5->6->NULL

当我们调用递归`reverse(head->next)`，会导致一下情况的出现（直接考虑结果即可）

![img](README.assets/3.jpg)

那么我们只需要对当前的结果进行处理即可

```cpp
reverse(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* last = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return last;
}
```

![img](README.assets/5.jpg)

##### 92 反转链表Ⅱ，递归算法

反转从位置 `left` 到位置 `right` 的链表节点，返回 **反转后的链表**

首先考虑反转前N个节点，整体与上面的反转链表没有太大差异

```cpp
ListNode* tail = nullptr;
ListNode* reverseN(ListNode* head, int n) {
    if (n == 1) {
        tail = head->next;
        return head;
    }
    ListNode* last = reverse(head->next, n-1);
    head->next->next = head;
    head->next = tail;
    return last;
}
```

![img](README.assets/7.jpg)

那么对于反转两个变量中间，就考虑当left为1的时候，就简化为上面的反转前N个节点；当left不为1的时候，那么对于当前节点，对于之后的节点调用函数，此时head->next = 之后翻转的头节点

```cpp
ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (left == 1) {
        return reverseN(head, right);
    }
    head->next = reverseBetween(head->next, left-1, right-1);
    return head;
}
```

##### 25 K个一组翻转链表

给你链表的头节点 `head` ，每 `k` 个节点一组进行翻转，请你返回修改后的链表

- 首先反转以head开头的前K个
- 将第 `k + 1` 个元素作为 `head` 递归调用 `reverseKGroup` 函数
- 将上面的结果链接起来

```cpp
ListNode* reverseKGroup(ListNode* head, int k) {
    // 首先反转前k个节点
    ListNode* tail = head;
    for (int i = 0; i < k; i++) {
        // 剩余的长度小于k，则不反转直接返回
        if (!tail) return head;
        tail = tail->next;
    }
    // 翻转从[head, tail)部分的节点
    ListNode* newhead = Reverse(head, tail);
    // 调用递归翻转后面的部分
    head->next = reverseKGroup(tail, k);
    return newhead;
}
```

![img](README.assets/6.jpg)

#### 判断回文链表

|                             题目                             | 难度 | 题解 |
| :----------------------------------------------------------: | :--: | :--: |
| [234. 回文链表](https://leetcode.cn/problems/palindrome-linked-list/) | 简单 | 234  |

##### 234 判断回文链表

1. 直接反转链表，然后判断，空间复杂度O(n)

2. 使用后序位置判断，空间复杂度O(n)

   ```c++
   left = head;
   return traverse(head);
   bool traverse(ListNode* right) {
       if (!right) return true;
       bool res = traverse(right->next);
       // 后续位置
       res = res && (left->val == right->val);
       left = left->next;
       return res;
   }
   ```

3. 空间优化为O(1)

   ```c++
       // 1.快慢指针找到中间结点
       ListNode* slow = head;
       ListNode* fast = head;
       while (fast && fast->next) {
           slow = slow->next;
           fast = fast->next->next;
       }
       // 奇数长度的起始点在中间结点的后面
       if (fast) {
           slow = slow->next;
       }
       // 2.反转slow之后的链表
       ListNode* right = reverse(slow);
       // 3.对比
       left = head;
       while (right && left)
       {
           if (right->val != left->val) {
               return false;
           }
           right = right->next;
           left = left->next;
       }
       return true;
   }
   
   ListNode* reverse(ListNode* head) {
       ListNode* pre = nullptr;
       ListNode* cur = head;
       ListNode* next;
       while (cur) {
           next = cur->next;
           cur->next = pre;
           pre = cur;
           cur = next;
       }
       return pre;
   }
   ```

   

### 数组

|                             题目                             |   难度   |                 题解                 |
| :----------------------------------------------------------: | :------: | :----------------------------------: |
| [26. 删除有序数组中的重复项](https://leetcode.cn/problems/remove-duplicates-from-sorted-array/) |   简单   |                                      |
| [27. 移除元素](https://leetcode.cn/problems/remove-element/) |   简单   |                                      |
| [380. O(1) 时间插入、删除和获取随机元素](https://leetcode.cn/problems/insert-delete-getrandom-o1/) |   中等   | 380常数时间删除-查找数组中的任意元素 |
| [710. 黑名单中的随机数](https://leetcode.cn/problems/random-pick-with-blacklist/) | **困难** |                                      |
| [316. 去除重复字母](https://leetcode.cn/problems/remove-duplicate-letters/) 一致 [1081. 不同字符的最小子序列](https://leetcode.cn/problems/smallest-subsequence-of-distinct-characters/) |   中等   |      去重问题，查看汇总去重问题      |

##### 380 常数时间删除-查找数组中的任意元素

- 对于删除，插入，查找操作时间复杂度为O(1)的数据结构有：`hash`，底层设计可以有数组和链表
- 但是要想随机选择一个数字，底层设计一定要为数组，但是数组的插入、删除如果要为常数时间，那么就需要在数组尾部进行插入和删除的操作

那么解法就是使用数组来存储元素，但是使用一个`hash`结构来保存元素对应的索引

```cpp
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
```



#### 前缀和数组

#### 二维数组的花式遍历法

|                             题目                             | 难度 |                             题解                             |
| :----------------------------------------------------------: | :--: | :----------------------------------------------------------: |
| [151. 反转字符串中的单词](https://leetcode.cn/problems/reverse-words-in-a-string/) | 中等 |                  先翻转全部，再翻转每个单词                  |
|  [48. 旋转图像](https://leetcode.cn/problems/rotate-image/)  | 中等 | [labuladong 题解](https://labuladong.github.io/article/slug.html?slug=rotate-image)[思路](https://leetcode.cn/problems/rotate-image/#) |
| [54. 螺旋矩阵](https://leetcode.cn/problems/spiral-matrix/)  | 中等 |                         设置四个边界                         |

##### 48.翻转图像

1. **先将 `n x n` 矩阵 `matrix` 按照左上到右下的对角线进行镜像对称**：

   ![img](README.assets/2.jpeg)

2. **再对矩阵的每一行进行反转**：

   ![img](README.assets/3.jpeg)

上面是对矩阵进行顺时针翻转，如果想要进行逆时针旋转90°，就可以：

1. 沿右对角线翻转
2. 再左右水平翻转

#### 前缀和数组

总体来说就是以【空间换时间】

**前缀和主要适用的场景是原始数组不会被修改的情况下，频繁查询某个区间的累加和**。

|                             题目                             | 难度 | 题解 |
| :----------------------------------------------------------: | :--: | :--: |
| [303. 区域和检索 - 数组不可变](https://leetcode.cn/problems/range-sum-query-immutable/) | 简单 |      |
| [304. 二维区域和检索 - 矩阵不可变](https://leetcode.cn/problems/range-sum-query-2d-immutable/) | 中等 | 304  |

##### 304 二维区域和检索

![img](README.assets/5.jpeg)

#### 差分数组

**差分数组的主要适用场景是频繁对原始数组的某个区间的元素进行增减**。

```cpp
int diff[nums.size()];
// 构造差分数组
diff[0] = nums[0];
for (int i = 1; i < nums.size(); i++) {
    diff[i] = nums[i] - nums[i - 1];
}
```
**这样构造差分数组 `diff`，就可以快速进行区间增减的操作**，如果你想对区间 `nums[i..j]` 的元素全部加 3，那么只需要让 `diff[i] += 3`，然后再让 `diff[j+1] -= 3` 即可

只要花费 O(1) 的时间修改 `diff` 数组，就相当于给 `nums` 的整个区间做了修改。多次修改 `diff`，然后通过 `diff` 数组反推，即可得到 `nums` 修改后的结果。

|                             题目                             | 难度 | 题解 |
| :----------------------------------------------------------: | :--: | :--: |
|                     370.区间加法（plus）                     | 中等 | 307  |
| [1109. 航班预订统计](https://leetcode.cn/problems/corporate-flight-bookings/) | 中等 |      |
|   [1094. 拼车](https://leetcode.cn/problems/car-pooling/)    | 中等 |      |

##### 370区间加法

![img](README.assets/title1.png)

```cpp
// 定义差分工具
class Difference {
public:
    int* diff;
    Difference(int* nums, int length) {
        assert(length > 0);
        diff = new int[length]();
        diff[0] = nums[0];
    }
    // 给区间[i, j]增加val
    void increment(int i, int j, int val) {
        diff[i] += val;
        if (j+1 < sizeof(diff)-sizeof(diff[0])) {
            diff[j+1] -= val;
        }
    }
	/* 返回结果数组 */
    int* result() {
        int* res = new int[sizeof(diff) / sizeof(diff[0])]();
        res[0] = diff[0];
        for (int i = 1; i < sizeof(diff) / sizeof(diff[0]); i++) {
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }
}
```



#### nsum问题

|                         题目                         | 难度 | 题解 |
| :--------------------------------------------------: | :--: | :--: |
| [1. 两数之和](https://leetcode.cn/problems/two-sum/) | 简单 |      |
|  [15. 三数之和](https://leetcode.cn/problems/3sum/)  | 中等 |      |
|  [18. 四数之和](https://leetcode.cn/problems/4sum/)  | 中等 |      |

#### 左右指针

|                             题目                             | 难度 |        题解        |
| :----------------------------------------------------------: | :--: | :----------------: |
| [167. 两数之和 II - 输入有序数组](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/) | 中等 |      左右指针      |
| [5. 最长回文子串](https://leetcode.cn/problems/longest-palindromic-substring/) | 中等 | 中间扩散的左右指针 |
|                                                              |      |                    |

#### 二分查找

|                             题目                             |   难度   |              题解               |
| :----------------------------------------------------------: | :------: | :-----------------------------: |
| [704. 二分查找](https://leetcode.cn/problems/binary-search/) |   简单   |         最基本二分查找          |
| [34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/) |   中等   |       中间扩散的左右指针        |
| [剑指 Offer 53 - I. 在排序数组中查找数字 I](https://leetcode.cn/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/) |   简单   |           34题的变式            |
| [528. 按权重随机选择](https://leetcode.cn/problems/random-pick-with-weight/) |   中等   |         前缀和+二分搜索         |
| [875. 爱吃香蕉的珂珂](https://leetcode.cn/problems/koko-eating-bananas/) |   中等   |          二分搜索运用           |
| [1011. 在 D 天内送达包裹的能力](https://leetcode.cn/problems/capacity-to-ship-packages-within-d-days/) |   中等   | 与875大致相似，但是需要细致分析 |
| [410. 分割数组的最大值](https://leetcode.cn/problems/split-array-largest-sum/) | **困难** |           改写为1011            |

##### 528 按权重随机选择

核心思路就说完了，主要分几步：

1、根据权重数组 `w` 生成前缀和数组 `preSum`。

2、生成一个取值在 `preSum` 之内的随机数，用二分搜索算法寻找大于等于这个随机数的最小元素索引。

3、最后对这个索引减一（因为前缀和数组有一位索引偏移），就可以作为权重数组的索引，即最终答案

```cpp
vector<int> presum;
Solution(vector<int>& w) {
    // 得到前缀和数组
    presum.resize(w.size()+1);
    presum[0] = 0;
    for (int i = 0; i < w.size(); i++) {
        presum[i+1] = presum[i]+w[i];
    }
}

int pickIndex() {
    int n = presum.size();
    // 得到在presum最大值范围内的随机数，不取0，所以结果要加一
    int target = (rand() % presum[n-1])+1;
    // 调用左侧二分查找算法得到大于等于target的下标
    // 注意这里的搜索范围为[1, presum_max]
    int left = 1, right = n-1;
    while (left <= right) {
        int mid = left + (right-left)/2;
        if (presum[mid] < target) {
            left = mid+1;
        }
        else if (presum[mid] > target) {
            right = mid - 1;
        }
        else {
            right = mid - 1;
        }
    }
    return left-1;
}
```

##### 857 爱吃香蕉的珂珂

首先考虑该题的`x`和`f(x)`是什么，很明显该题的`x`就是**吃掉香蕉的速度**，而明显速度与花费时间是一个单调递减函数，所以`f(x)`函数就可以确定了，注意这里的`hours`需要使用`long`

```cpp
// 通过速度计算出此时吃完所有需要的时间
long f(vector<int>& pils, int k) {
    long hours = 0;
    for (int pils : pils) {
        hours += pils / k;
        if (pils % k > 0) {
            hours++;
        }
    }
    return hours;
}
```

然后就是主体函数，很明显这里的`target`就是我们给出的`h`，然后找到最小的`x`

考虑二分搜索的`left`和`right`，明显这里的最小速度为1，而最大速度就是香蕉数的最大值

再考虑使用哪个边界，脑海中可以给出一个函数图，是单调递减的，而我们要求最小的k，因此应该是求左边界，因此主体部分就可以得到，这里需要注意由于函数是单调递减，因此考虑边界收缩时需要多多注意

```cpp
int minEatingSpeed(vector<int>& piles, int h) {
    // 这里k取值最小为1，最大为每小时最大香蕉数
    int left = 1, right = 0;
    for (int pile : piles) {
        right = max(right, pile);
    }
    // 找最小的k，所以为左边界二分搜索
    while (left <= right) {
        int mid = left + (right - left)/2;
        if (f(piles, mid) <= h) {
            right = mid-1;
        }
        else {
            left = mid+1;
        }
    }
    return left;
}
```

##### 410 分割数组的最大值

原题目：给定一个数组`nums`，将这个数组分割为`m`个非空的连续子数组，求这`m`个子数组各自和的最大值的最小值

改写为：一艘货船，每个货物的重量是`nums[i]`，现在需要在`m`天内将这些货物运走，求货船的最小载重是多少？也就变为1011题了。

分析：

- 这里x为最小载重，f(x)返回运完需要的天数，target就为需要的天数m
- left为每个货物的重量的最大值（也就是`m=nums.size()`），right为总货物（也就是一天就运完，m=1），因为是求最小载重，因此为左边界问题

```cpp
int f(vector<int>& nums, int c) {
    int day = 0;
    int total = 0;
    for (int num : nums) {
        total += num;
        if (total > c) {
            day++;
            total = num;
        }
    }
    if (total > 0) {
        day++;
    }
    return day;
}
int splitArray(vector<int>& nums, int k) {
    int left = 0, right = 0;
    for (int num : nums) {
        left = max(left, num);
        right += num;
    }
    while (left <= right) {
        int mid = left + (right-left)/2;
        if (f(nums, mid) <= k) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}
```



#### 滑动窗口

|                             题目                             | 难度 |       题解        |
| :----------------------------------------------------------: | :--: | :---------------: |
| [76. 最小覆盖子串](https://leetcode.cn/problems/minimum-window-substring/) | 困难 |     滑动窗口      |
| [567. 字符串的排列](https://leetcode.cn/problems/permutation-in-string/) | 中等 |     滑动窗口      |
| [438. 找到字符串中所有字母异位词](https://leetcode.cn/problems/find-all-anagrams-in-a-string/) | 中等 |     滑动窗口      |
| [3. 无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters/) | 中等 |     滑动窗口      |
| [187. 重复的DNA序列](https://leetcode.cn/problems/repeated-dna-sequences/) | 中等 |  kabin karp算法   |
| [28. 找出字符串中第一个匹配项的下标](https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/) | 中等 | kabin karp算法 28 |

##### 76 最小覆盖子串

1. 什么时候应该移动 `right` 扩大窗口？窗口加入字符时，应该更新哪些数据？

   如果一个字符进入窗口，应该增加 `window` 计数器；

2. 什么时候窗口应该暂停扩大，开始移动 `left` 缩小窗口？从窗口移出字符时，应该更新哪些数据？

   当此时满足需要的字符的时候停止扩大；移出字符时需要更新window计数器

3. 我们要的结果应该在扩大窗口时还是缩小窗口时进行更新？

   缩小的时候进行

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t) {
            need[c]++;
        }
        int left = 0, right = 0;
        int start = 0, len = __INT32_MAX__;
        int vaild = 0;
        while (right < s.size()) {
            // c是移入的字符，之后扩大窗口
            char c = s[right++];
            // 如果c是需要的字符，那么更新窗口并且更新vaild
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    vaild++;
                }
            }

            // 判断左侧是否要收缩
            while (left < right && vaild == need.size()) {
                // 更新最小串
                if (right-left < len) {
                    start = left;
                    len = right-left;
                }
                // 需要收缩的字符
                char d = s[left++];
                if (need.count(d)) {
                    window[d]--;
                    // 如果不满足need的条件，vaild减小
                    if (window[d] < need[d]) {
                        vaild--;
                    }
                }
            }
        }
        return len == __INT32_MAX__ ? "":s.substr(start, len);
    }
};
```

##### 28 找出字符串中第一个匹配项的下标

```cpp
// kabin karp滑动窗口算法
class Solution {
public:
    int strStr(string haystack, string needle) {
        // 位数
        int L = needle.size();
        // 进制数,ASCLL编码
        int R = 256;
        // 设置一个较大的素数作为hash码
        long Q = 1658598167;
        long RL =  1;
        for (int i = 1; i < L; i++) {
            RL = (RL*R) % Q;
        }
        // 计算匹配字符串的hash数
        long needlehash = 0;
        for (int i = 0; i < needle.size(); i++) {
            needlehash = (needlehash*R+needle[i]) % Q;
        }
        int left = 0, right = 0;
        long windowhash = 0;
        while (right < haystack.size()) {
            windowhash = (windowhash*R+haystack[right]) % Q;
            right++;

            while (left < right && right-left == L) {
                if (windowhash == needlehash) {
                    // 还需进一步确认窗口子串是否真的和模式串相同，避免哈希冲突
                    if (needle == haystack.substr(left, L)) {
                        return left;
                    }
                }
                // 这里加上Q的原因是防止windowhash减之后为负值，加上Q可以防止为负值
                windowhash = (windowhash - (haystack[left]*RL)%Q+Q)%Q;
                left++;
            }
        }
        return -1;
    }
};
```

