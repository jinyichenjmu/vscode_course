#include <iostream> 
using namespace std;

const int Rows = 10;
const int Cols = 10;
const int MaxSize = Rows * Cols;

const int maze[Rows][Cols] = {
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
    int pre;
};

void PrintPath(const Box queue[], int endIdx)
{
    int path[MaxSize];
    int length = 0;

    for(int i = endIdx; i != -1; i = queue[i].pre)
    {
        path[length] = i;
        length ++;
    }

    for(int i = length - 1; i >= 0; i--)
    {
        int index = path[i];
        cout << '(' << queue[index].row << ", " << queue[index].col << ") ";
    }
}

bool FindPath(int startRow, int startCol, int endRow, int endCol)
{
    if(startRow < 0 || startRow >= Rows || startCol < 0 || startCol >= Cols ||
    endRow < 0 || endRow >= Rows || endCol < 0 || endCol >= Cols ||
    maze[startRow][startCol] != 0 || maze[endRow][endCol] != 0)
    {
        return false;
    }

    Box queue[MaxSize];
    bool visited[Rows][Cols] = {};

    int head = 0;       //指向待处理
    int tail = 0;       //指向待写入

    queue[tail] = {startRow, startCol, -1};
    tail ++;
    visited[startRow][startCol] = true;

    //上、右、下、左
    const int dr[] = {-1, 0, 1, 0};
    const int dc[] = {0, 1, 0, -1};

    while(head < tail)
    {
        int currentIdx = head;
        Box current = queue[head];
        head ++;
        
        if(current.row == endRow && current.col == endCol)
        {
            PrintPath(queue, currentIdx);
            return true;
        }

        // 将当前格子周围所有可走且未发现的格子入队。
        for(int i = 0; i < 4; i++)
        {
            int nextRow = current.row + dr[i];
            int nextCol = current.col + dc[i];

            if(nextRow >= 0 && nextRow <Rows && nextCol >= 0 && nextCol < Cols && !visited[nextRow][nextCol] && maze[nextRow][nextCol] == 0)
            {
                visited[nextRow][nextCol] = true;

                queue[tail] = {nextRow, nextCol, currentIdx};
                tail ++;
            }
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