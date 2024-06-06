#include <bits/stdc++.h>
#include "TickTacToe/Game.cpp"
using namespace std;

int main()
{
    srand(time(0));
    bool userPlayFirst=true;
    Game *g = new Game(3,userPlayFirst);
    g->play();
    return 0;
}