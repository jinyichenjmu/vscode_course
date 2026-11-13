#include <iostream>
#include <vector>
using namespace std;

int maze[10][10] = {};

struct box{
    int x;
    int y;
};

void FindPath(int x1, int y1, int x2, int y2, vector<box> &path, int &count)
{
    if(x1 < 1 || x1 > x2 || y1 < 1 || y1 > y2 || maze[x1][y1] != 0)
    {
        return;
    }

    path.push_back({x1, y1});

    if(x1 == x2 && y1 == y2)
    {
        count ++;
        cout << "Path " << count << ": ";

        for(const box box : path)
        {
            cout << "(" << box.x << "," << box.y << ") ";
        }
        cout << endl;
    }
    else
    {
        maze[x1][y1] = -1;

        FindPath(x1 + 1, y1, x2, y2, path, count);
        FindPath(x1, y1 + 1, x2, y2, path, count);

        maze[x1][y1] = 0;
    }

    path.pop_back();
}

int main()
{
    vector<box> path;
    int count = 0;

    FindPath(1, 1, 3, 3, path, count);

    cout << "Total paths: " << count << '\n';

    return 0;
}