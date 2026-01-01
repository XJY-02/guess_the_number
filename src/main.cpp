// main.cpp
#include "AI.h"
#include "Game.h"
#include "GameStats.h"
#include "Player.h"

int main() {
    AI ai;
    Player player;
    Game game(1, 100);
    game.start(ai, player);
    return 0;
}