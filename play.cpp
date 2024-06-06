#include <bits/stdc++.h>
#include "TicTacToe/Game.cpp"
using namespace std;

int main()
{
    srand(time(0));
    bool userPlayFirst=false;
    Game *g = new Game(3,userPlayFirst);
    g->play();
    return 0;
}