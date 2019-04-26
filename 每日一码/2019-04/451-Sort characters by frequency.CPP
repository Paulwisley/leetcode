#include "../INCLUDE/GLOBAL.H"
string frequencySort(string s) {
    unordered_map<char, int> mp;
    string ans;
    if(s.empty()) return ans;
    for(char c : s){
        mp[c]++;
    }
    vector<string> tmp(s.length()+1, "");
    for(auto &key:mp){
        tmp[key.second].append(key.second, key.first);
    }
    for(int i = tmp.size()-1; i >= 0; --i){
        if(!tmp[i].empty()) ans.append(tmp[i]);
    }
    return ans;
}

/*
    题目描述： 给定一个字符串str, 比如：ahjjkksss, 按照字符串中字符的频率降序组成新的字符串，并输出。
    分析：
        利用一张map来存储所有的字符集合，比如对于上述例串我们可以得到这样的一个串集合： { a:1, h:1, j:2, k:2, s:3}
        利用桶排序，将集合进行排序 得到一张降序集合，然后重新组成字符串并输出。

        这里的桶排序是一种比较激进的解法，耗费了空间来换取时间的改进，虽然时间复杂度只有O(n)但是并不觉得是一种最优解法，因为空间复杂度比较高。

        当然常规的思路是使用了红黑树进行排序，即调用stl内建的sort函数，然后再对串进行重组。
        
        埋坑：看到有人使用priority_queue(优先级队列),make_head(建堆)来解决这个问题，其中使用堆排序的代码居然还是最省时的，有点难以置信，有时间要分析下。
        due：2019-05-01

*/