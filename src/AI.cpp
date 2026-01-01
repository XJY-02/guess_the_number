#include "AI.h"

#include <iostream>
#include <random>
using namespace std;

void AI::set_random_int(int low, int high) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(low, high);
    random_int = dis(gen);
    cout << "AI: 我已挑好数字，来猜猜看吧！" << endl;
}

void AI::check_and_set_result(int answer) {
    if (answer > random_int) {
        res = Result::Big;
    } else if (answer < random_int) {
        res = Result::Small;
    } else {
        res = Result::Equal;
    }
}

void AI::report_result() const {
    switch (res) {
        case Result::Big:
            cout << "AI: 大了" << endl;
            break;
        case Result::Small:
            cout << "AI: 小了" << endl;
            break;
        case Result::Equal:
            cout << "AI: 恭喜你，你猜对了！" << endl;
            break;
        default:
            break;
    }
}