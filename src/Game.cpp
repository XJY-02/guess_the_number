#include "Game.h"

#include <iostream>

using namespace std;


void Game::hello() const {
    cout << "欢迎来到猜数字游戏，AI会从" << ini_low << '~' << ini_high
         << "中选择一个整数，你需要猜中它，AI会在你每次猜测后给出范围提示" << endl;
}


void Game::bye() const { cout << "游戏结束，感谢游玩！" << endl; }


void Game::start(AI& ai, Player& player) {
    is_running = true;                     // game设置游戏开始
    hello();                               // 游戏开场白
    ai.set_random_int(ini_low, ini_high);  // AI确定随机数
    while (is_running) {                   // 游戏进行中
        int current_low = stats.get_current_low();
        int current_high = stats.get_current_high();
        stats.player_try();
        cout << "当前范围为" << current_low << '~' << current_high << endl;  // 输出当前可选范围
        player.set_answer(current_low, current_high);                        // 玩家设置合理答案
        ai.check_and_set_result(player.get_answer());                        // ai检查答案并设置结果
        ai.report_result();                                                  // ai报告结果
        if (ai.is_gameover()) {                                              // ai判断游戏结束
            cout << "你总共尝试了 " << stats.get_player_try_count() << "次"
                 << endl;                              // 输出尝试次数
            if (play_again()) {                        // game询问是否再玩一把
                stats.reset_stats(ini_low, ini_high);  // 重置统计信息
                ai.set_random_int(ini_low, ini_high);  // AI重新确定随机数
            } else
                is_running = false;  // game设置游戏结束
        }
    }
    bye();      // 游戏结束致辞
    cin.get();  // 等待回车退出...
}

bool Game::play_again() const {
    cout << "是否再来一把?(yes/no):";

    string input;

    while (true) {
        // 读取输入
        if (!(cin >> input)) {  // 读取失败
            cout << "读取失败" << endl;
            cin.clear();             // 清除错误标志
            cin.ignore(1000, '\n');  // 丢弃错误输入（丢弃至多1000个字符，丢弃\n或EOF后提前停止）
            continue;
        }
        // 读取成功
        cin.ignore(1000, '\n');  // 清理多余输入
        if (input == "yes") {
            return true;
        } else if (input == "no") {
            return false;
        } else {
            cout << "输入yes/no: ";
        }
    }
}