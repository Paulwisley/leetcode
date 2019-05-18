#include "../INCLUDE/GLOBAL.H"
auto __ = []() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
int main()
{
    /*
    Input:
        First Line: Num of the players [5, 10]
        Second Line: Name of each player
        Third Line: points of the game
    */

    int num;
    cin >> num; // 队员数
    if (num < 5 || num > 10)
        return 0;
    vector<string> players(num);
    for (auto &s : players)
    {
        cin >> s;
    } //初始化队员名

    string points;
    cin >> points;
    //初始化 积分情况
    int pLen = points.size();
    if (pLen > 1000)
        return 0;
    //算法思想 找出最大连续长度 并记录最长位置索引 然后 走游戏流程  将符合条件队员加入 vector数组

    vector<string> White(2);                 // 白队
    vector<string> Black(2);                 // 黑队
    vector<string> Line(players.size() - 4); // 排队等候
    // 初始化 各队队员
    White[0] = players[0];
    White[1] = players[2];
    Black[0] = players[1];
    Black[1] = players[3];
    copy(players.begin() + 4, players.end(), Line.begin());

    vector<int> record(pLen, 0);
    //用record来记录 最长连续子串和对应的索引
    record[0] = 1;
    int start = 0;
    int _max = 0;
    forall(i, 1, pLen)
    {
        if (points[i] == points[i - 1])
        {
            ++record[start];
        }
        else
        {
            start = i;
            ++record[start];
        }
        _max = max(_max, record[start]);
    }

    //模拟游戏进程 并且将对应max位置的队员 加入ans数组
    // 这里有坑 要求输出是要按照进入 当前序列的先后顺序
    vector<vector<string>> ans;
    forall(i, 0, pLen)
    {
        if (points[i] == 'W')
        {
            if (record[i] == _max)
            {
                if (i != 0)
                    ans.push_back({White[1], White[0]});
                else
                    ans.push_back(White);
            }
            swap(White[0], White[1]); // 白队攻防转换
            Line.push_back(Black[1]); // 黑队 反手队员加入等待队列
            Black[1] = Black[0];      // 将等待队员首位成员 变为攻击队员 原攻击队员变为防守队员
            Black[0] = Line[0];
            //将等待队列首位移除
            Line.erase(Line.begin());
        }
        else
        {
            //跟 白队赢球一样处理
            if (record[i] == _max)
            {
                if (i == 0)
                    ans.push_back(Black);
                else
                    ans.push_back({Black[1], Black[0]});
            }                         //先判断是否是最大连续串
            swap(Black[0], Black[1]); // 黑队攻防转换
            Line.push_back(White[1]); //白队的防守队员加入等待队列
            White[1] = White[0];      // 白队攻击队员变防守
            White[0] = Line[0];       // 白队 的防守队员移入等待队列
            //等待队列首位移除
            Line.erase(Line.begin());
        }
    }

    //将ans输出
    for (auto player : ans)
    {
        for (auto p : player)
        {
            cout << p << " ";
        }
        cout << endl;
    }

    return 0;
}