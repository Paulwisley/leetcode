#ifndef GLOBALHEAD
#define GLOBALHEAD
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <fstream>
#include <cmath>
#include <limits>
#include <set>
#include <list> //STL list
#include <map>  // STL map
#include <unordered_map>
#include <queue>      // STL queue
#include <stack>      //sTL stack
#include <bitset>     //bitset可按位定义串
#include <algorithm>  //STL各种算法 比如 swap sort merge max min 比较
#include <numeric>    //常用数字操作 一般和algorithm搭配使用
#include <functional> //STL定义运算函数（代替运算符）
#include <iterator>

#define forall(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define input(a)      \
    for (auto &x : a) \
        cin >> x;
using namespace std;

#endif