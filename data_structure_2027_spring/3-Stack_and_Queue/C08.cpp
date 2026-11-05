#include <iostream>
using namespace std;

const int Rows = 10;
const int Cols = 10;
const int MaxSize = Rows * Cols;

int maze[Rows][Cols] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};

struct Box{
    int row;
    int col;
    int dir;        //已尝试到的方向，-1 表示尚未尝试
};

struct PathStack{
    Box data[MaxSize];
    int top;
};

bool FindPath(int startRow, int startCol, int endRow, int endCol)
{
    PathStack s{{},-1};

    const int dr[] = {-1, 0, 1, 0};
    const int dc[] = {0, 1, 0, -1};

    if (startRow < 1 || startRow >= Rows - 1 || startCol < 1 || startCol >= Cols - 1 ||
        endRow < 1 || endRow >= Rows - 1 || endCol < 1 || endCol >= Cols - 1 ||
        maze[startRow][startCol] != 0 || maze[endRow][endCol] != 0)
    {
        return false;
    }

    s.data[++s.top] = {startRow,startCol,-1};
    maze[startRow][startCol] = -1;
    
    while(s.top != -1)
    {
        Box &current = s.data[s.top];

        if(current.row == endRow && current.col == endCol)
        {
            for(int i = 0;i<=s.top;i++)
            {
                cout << '(' << s.data[i].row << ", " << s.data[i].col << ") ";
            }
            cout << endl;

            return true;
        }

        if(current.dir == 3)
        {
            maze[current.row][current.col] = 0;
            s.top--;
            continue;
        }

        current.dir ++;
        int d = current.dir;

        int nextRow = current.row + dr[d];
        int nextCol = current.col + dc[d];

        if(nextRow >= 0 && nextRow < Rows && nextCol >= 0 && nextCol < Cols && maze[nextRow][nextCol] == 0)
        {
            maze[nextRow][nextCol] = -1;
            s.data[++s.top] = {nextRow,nextCol,-1};
        }
    }
    return false;
}

int main() {
    if (!FindPath(1, 1, 8, 8)) {
        cout << "No path.\n";
    }

    return 0;
}