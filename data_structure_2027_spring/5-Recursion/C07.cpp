#include <iostream>
#include <vector>
using namespace std;

struct task{
    int n;
    char x;
    char y;
    char z;
    bool flag;
};

void Hanoi2(int n, char x, char y, char z)
{
    if(n <= 0)
    {
        return;
    }

    vector<task> st;

    st.push_back({n, x, y, z, n == 1});

    while(!st.empty())
    {
        task e = st.back();
        st.pop_back();

        if(e.flag)
        {
            cout << "Move disk " << e.n << " from " << e.x << " to " << e.z << endl;
        }
        else
        {
            // 按 C、B、A 的顺序入栈

            // C：上面的盘子从 y 移到 z，借助 x
            task c{e.n - 1, e.y, e.x, e.z, e.n - 1 == 1};
            st.push_back(c);

            // B：最大的盘子从 x 移到 z
            task b{e.n, e.x, e.y, e.z, true};
            st.push_back(b);

            // A：上面的盘子从 x 移到 y，借助 z
            task a{e.n - 1, e.x, e.z, e.y, e.n - 1 == 1};
            st.push_back(a);
        }
    }
}

int main()
{
    Hanoi2(2, 'X', 'Y', 'Z');
    return 0;
}
