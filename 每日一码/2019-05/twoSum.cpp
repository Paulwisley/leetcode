#include "../INCLUDE/GLOBAL.H"

string alignHelper(string str, int len)
{
    str.insert(str.begin(), len, '0');
    return str;
}

bool isDigit(string cur)
{
    for (auto p : cur)
    {
        if (p - '0' > 10)
            return false;
    }
    return true;
}

int main()
{
    string a, b;
    cin >> a >> b;
    string output;
    int len_a = a.size();
    int len_b = b.size();
    //字符串验证 若为空或者非digit字符串 直接返回
    if (!isDigit(a) || !isDigit(b))
        return 0;
    if (len_a > len_b)
        b = alignHelper(b, len_a - len_b);
    else
        a = alignHelper(a, len_b - len_a);
    int tmp = 0; // 用来表示进位
    int len = max(len_a, len_b);
    // cout << "a = " << a << "b = " << b << endl;
    for (int i = len - 1; i >= 0; --i)
    {
        int cur = (a[i] - '0' + b[i] - '0') % 10;
        output.insert(output.begin(), 1, cur + tmp + '0');
        tmp = (a[i] - '0' + b[i] - '0') / 10;
    }
    cout << output << endl;
    return 0;
}