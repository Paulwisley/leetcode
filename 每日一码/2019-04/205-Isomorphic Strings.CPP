#include "../INCLUDE/GLOBAL.H"
    bool isIsomorphic(string s, string t) {
        set<string> sum;
        set<char> A;
        set<char> B;
        for(int i = 0; i < s.size(); ++i){
            string tmp;
            tmp.push_back(s[i]);
            tmp.push_back(t[i]);
            sum.insert(tmp);
            // cout<<s[i]+t[i]<<endl;
            A.insert(s[i]);
            B.insert(t[i]);
        }
        if(sum.size()==A.size()&&A.size()==B.size())
            return true;
        else
            return false;
    }

    bool improved(string s, string t){
        char setA[128] = {0};
        char setB[128] = {0};
        int len = s.size();
        for(int i = 0; i < len; ++i){
            if(setA[s[i]] != setB[t[i]]) return false;
            ++setA[s[i]];
            ++setB[t[i]];
        }
        return true;
    }

    /*
        题目描述：给定两个串 A-"abcab", B-"efhef"  问这两个串是否可以提取出一种模式, 使得这两个串之间的每个字符存在一种一一对应的关系。
        分析：
            首先不妨设两个串的长度一致，否则直接return false。
            在长度一致的条件下，我们可以考虑根据当前字符第一次出现的索引做字符的重编码：a - 1, b - 2 ... 
            以此类推每个串都可以得到 一个唯一的集合，该集合描述了当前串的模式串的形式，如，串 "abcab" 可以得到 {a:1, b:2, c:3},由此得到的模式串 12321
            相应的串 "efhef" 可以得到{e:1, f:2, h:3}, 由此得到的模式串 12321 
            当两个串得到的模式串一致时，我们认为这两个串满足这样的(字符一一对应)关系。

            当然 一种改良的做法是，直接 将A，B 两个串的每个子字符进行拼接，得到一个新的串C，如果 set(A) = set(B) = set(A+B)
            那么我们便说当前串满足这样的一种关系

            借助于hash的思想，我们可以再次改良该算法
            先初始化两个数组，大小128, 值为0, 可以用来存放所有的字符，key 和 value 分别对应 当前字符和该字符出现的次数
            遍历字符串，如果该字符出现的次数不一致则说明 当前串不满足该映射关系，若一致，则将出现次数++, 并继续往下check下一个字符
            遍历结束，输出 true
    */

