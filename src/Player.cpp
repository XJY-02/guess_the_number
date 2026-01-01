#include "Player.h"

#include <iostream>
#include <limits>
using namespace std;

void Player::set_answer(int low, int high) {
    cout << "到你了，请输入答案: ";

    while (true) {
        // 当读取失败
        if (!(cin >> answer)) {
            cout << "输入错误！请输入一个整数：";
            cin.clear();             // 清除错误标志
            cin.ignore(1000, '\n');  // 丢弃错误输入（丢弃至多1000个字符，丢弃\n或EOF后提前停止）
            continue;
        }
        // 读取成功
        cin.ignore(1000, '\n');  // 清理多余输入
        if (answer < low || answer > high) {
            cout << "请在" << low << '~' << high << "之间选一个整数:";
            continue;
        }
        break;
    }
}