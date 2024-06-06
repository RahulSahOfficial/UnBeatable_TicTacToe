void Game::display()
{
    cout << endl<< " -------------" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << " | ";
            if (grid[i][j] == "O" || grid[i][j] == "X")
                cout << grid[i][j];
            else
                cout << " ";
        }
        cout << " | " << endl;
        cout << " -------------" << endl;
    }
}