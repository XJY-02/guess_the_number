#ifndef PLAYER_H
#define PLAYER_H

class Player {
   private:
    int answer;  // 玩家的答案
   public:
    // 玩家猜数（设置答案）
    void set_answer(int low,int high);
    // 获取玩家猜的数
    inline int get_answer() const { return answer; };
};

#endif