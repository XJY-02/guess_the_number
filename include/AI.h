#ifndef AI_H
#define AI_H
// 枚举结果
enum class Result { Big, Small, Equal };

class AI {
   private:
    int random_int;  // AI猜的数
    Result res;      // 判断结果

   public:
    // AI出题（生成随机数）
    void set_random_int(int low, int high);
    // AI检查回答并设置判断结果
    void check_and_set_result(int answer);
    // AI报告判断结果
    void report_result() const;
    // AI判断是否结束游戏
    bool is_gameover() const { return res == Result::Equal; };
};

#endif