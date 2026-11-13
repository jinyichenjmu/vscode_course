#include <iostream>
#include <vector>
using namespace std;

const int Rows = 6;
const int Cols = 6;

// 0 表示可走，1 表示墙
int maze[Rows][Cols] = {
    {1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 1},
    {1, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 1, 1},
    {1, 1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1}
};

struct Box
{
    int row;
    int col;
};

void FindPath(int row, int col, int endRow, int endCol, vector<Box> &path, int &count)
{
    if(row < 0 || row >= Rows || col < 0 || col >= Cols)
    {
        return;
    }

    if(maze[row][col] != 0)
    {
        return;
    }

    path.push_back({row,col});

    if(row == endRow && col == endCol)
    {
        count ++;
        cout << "Path " << count << ": ";
        
        for(const Box &box : path)
        {
            cout << "(" << box.row << "," << box.col << ") ";
        }
        cout << endl;
    }
    else
    {
        maze[row][col] = -1;

        FindPath(row - 1, col, endRow, endCol, path, count);
        FindPath(row + 1, col, endRow, endCol, path, count);
        FindPath(row, col - 1, endRow, endCol, path, count);
        FindPath(row, col + 1, endRow, endCol, path, count);

        maze[row][col] = 0;
    }
    path.pop_back();
}

int main()
{
    vector<Box> path;
    int count = 0;

    FindPath(1, 1, 4, 4, path, count);

    cout << "Total paths: " << count << '\n';

    return 0;
}