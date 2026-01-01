#ifndef GAMESTATS_H
#define GAMESTATS_H

class GameStats {
   private:
    int player_try_count;           // 玩家尝试次数
    int current_low, current_high;  // 当前上下限

   public:
    // 默认构造函数
    GameStats(int ini_low, int ini_high)
        : player_try_count(0), current_low(ini_low), current_high(ini_high) {}

    // 玩家尝试次数getter
    int get_player_try_count() const { return player_try_count; }
    // 玩家进行一次尝试
    void player_try() { player_try_count++; };
    // 当前下限getter
    int get_current_low() const { return current_low; }
    // 当前上限getter
    int get_current_high() const { return current_high; }
    // 重置游戏状态
    void reset_stats(int ini_low, int ini_high) {
        player_try_count = 0;
        current_low = ini_low;
        current_high = ini_high;
    }
};


#endif
