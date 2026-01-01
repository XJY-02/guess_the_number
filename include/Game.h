#ifndef GAME_H
#define GAME_H


#include "AI.h"
#include "GameStats.h"
#include "Player.h"

class Game {
   private:
    int ini_low, ini_high;  // 猜数字的初始上下限
    bool is_running;        // 游戏运行标志
    GameStats stats;        // 游戏统计信息

   public:
    // 传入猜数字上下限构造游戏对象
    Game(int ini_low, int ini_high)
        : ini_low(ini_low), ini_high(ini_high), stats(ini_low, ini_high) {};

    // 游戏开场白
    void hello() const;

    // 游戏结束致辞
    void bye() const;

    // 游戏开始(传入ai和玩家的引用)
    void start(AI& ai, Player& player);

    // 游戏是否再来一把
    bool play_again() const;
};

#endif