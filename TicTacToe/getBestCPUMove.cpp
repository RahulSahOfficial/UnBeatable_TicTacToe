void Game::getBestCPUMove()
{
    cout << "CPU MOVE" << endl;
    int bestX, bestY, score, maxScore = INT_MIN, idx, val = 1 << 30;
    vector<pair<int, int>> poss;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            score = 0;
            if (grid[x][y] != 'X' && grid[x][y] != 'O')
            {
                char temp = grid[x][y];
                grid[x][y] = 'O';
                checkState(x, y, false);
                if (isGameOver && winner == "CPU")
                    score += val;
                else
                    score -= tryUserAllMove(val / 2);
                if (score == maxScore)
                    poss.push_back({x, y});
                else if (score > maxScore)
                {
                    maxScore = score;
                    poss.clear();
                    poss.push_back({x, y});
                }
                clearLastMove(x, y, false);
                grid[x][y] = temp;
            }
        }
    }
    idx = rand() % poss.size();
    bestX = poss[idx].first;
    bestY = poss[idx].second;
    grid[bestX][bestY] = 'O';
    checkState(bestX, bestY, false);
}