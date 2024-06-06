void Game::play()
{
    while (!isGameOver)
    {
        display();
        if (filled % 2 == !userFirst)
            input();
        else
            getBestCPUMove();
    }
    display();
    if (winner == "DRAW")
        cout << "MATCH DRAW" << endl;
    else
        cout << "Winner : " << winner;
}