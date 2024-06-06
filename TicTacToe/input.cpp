void Game::input()
{
    cout << "Your Turn : " << endl;
    bool inputSuccessful = false;
    int inp, x, y;
    while (!inputSuccessful)
    {
        cout << "Enter the number : ";
        cin >> inp;
        x = (inp - 1) / n;
        y = (inp - 1) % n;
        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == ' ')
        {
            grid[x][y] = 'X';
            inputSuccessful = true;
            checkState(x, y, true);
        }
    }
}