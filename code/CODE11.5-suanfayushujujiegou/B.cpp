#include <iostream>  // 提供 cin 和 cout，用于输入、输出
#include <string>    // 提供 string，用于保存队伍名称
#include <vector>    // 提供 vector，用作可以增长的数组
using namespace std; // 使用标准库中的名称时，可以省略 std::

int main() // 程序从 main 函数开始执行
{ // main 函数开始
    vector<string> tree(1); // 先放一个空字符串占据下标 0，实际数据从下标 1 开始
    string name; // 保存当前读入的队伍名称

    while (cin >> name && name != "#") // 读取一个名称；读取成功且不是 # 时继续
    { // 读取比赛结果的循环开始
        tree.push_back(name); // 把名称添加到数组末尾，保持题目给定的层序
    } // 读取比赛结果的循环结束，# 不会存入数组

    int n = (int)tree.size() - 1; // 数组元素总数减去占位元素，得到树的结点总数
    int t; // 保存查询次数
    cin >> t; // 读取查询次数

    for (int q = 0; q < t; q++) // 共处理 t 次查询
    { // 一次查询开始
        cin >> name; // 读取本次要查询的队伍名称
        int pos = 0; // 保存该队伍的叶子结点下标，0 表示尚未找到

        for (int i = n / 2 + 1; i <= n; i++) // 遍历最底层的全部参赛队伍
        { // 查找队伍的循环开始
            if (tree[i] == name) // 判断当前叶子结点是否是要找的队伍
            { // 找到队伍时执行
                pos = i; // 记录它在最底层的位置
                break; // 已经找到，结束查找队伍的内层 for 循环
            } // 找到队伍的分支结束
        } // 查找队伍的循环结束

        if (pos == 0) // 查找结束仍为 0，说明没有这支队伍
        { // 未找到队伍时执行
            cout << "Not Found\n"; // 按题目要求输出 Not Found，并换行
            continue; // 跳过本次查询后面的代码，开始下一次查询
        } // 未找到队伍的分支结束

        int games = 0; // 记录已经参加的比赛场数，初始为 0
        string result = "Champion!"; // 若向上检查时没有输过，最终就输出 Champion!

        while (pos > 1) // 当前位置不是根结点时，还能向上检查一场比赛
        { // 向上检查比赛的循环开始
            int parent = pos / 2; // 利用整数除法求父结点下标
            games++; // 参加了这一场比赛，无论输赢都要计数

            if (tree[parent] != name) // 父结点是本场胜者，名称不同就说明自己输了
            { // 被淘汰时执行
                result = tree[parent]; // 保存淘汰自己的队伍名称
                break; // 已被淘汰，结束向上检查比赛的 while 循环
            } // 被淘汰的分支结束

            pos = parent; // 本场获胜，移动到父结点，继续检查下一轮
        } // 向上检查比赛的循环结束

        cout << games << ' ' << result << '\n'; // 输出场次、一个空格和结果，最后换行
    } // 本次查询结束，进入下一次查询

    return 0; // 程序正常结束
} // main 函数结束