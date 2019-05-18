#include "../INCLUDE/GLOBAL.H"

vector<int> findAnagrams(string s, string p)
{
    vector<int> ans;
    vector<int> window(26, 0);
    for (char c : p)
        ++window[c - 'a'];
    int left = 0, right = 0, count = 0;
    int slen = s.length(), plen = p.length();
    if (plen > slen)
        return ans;
    while (right < slen)
    {
        if (window[s[right] - 'a'] >= 1)
            ++count;
        --window[s[right] - 'a'];
        ++right;
        if (count == plen)
            ans.push_back(left);
        //离开窗口，判断最左边元素是否有效，即之前是否被处理过
        //目的是在进行下一个窗口判断时，保证set集合的不变性
        if (right - left == plen)
        {
            if (window[s[left] - 'a'] >= 0)
                --count;
            ++window[s[left] - 'a'];
            ++left;
        }
    }
    return ans;
}

/*
    题目描述：在待匹配串S 中 找到 模式串的 所有同字母（可异序）子串 返回所有的这样的索引
    example：
    Input:
    s: "cbaebabacd" p: "abc"
    Output：
    [0,6]

    #解题思路
    使用滑动窗口的思想来处理这题。
    先遍历一趟原字符串，将原字符串 用一张set来维护，如{a:3, b:3, c:2, d:1, e:1},这里为了节省资源并利于操作，可以直接使用vector来模拟
    然后再使用滑动窗口来二次遍历字符串，因为不考虑顺序，所以无所谓匹配串元素在set中是何顺序存放
    在窗口内进行这样的操作：

*/