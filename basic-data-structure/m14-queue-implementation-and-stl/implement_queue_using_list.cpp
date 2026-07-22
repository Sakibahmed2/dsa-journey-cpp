#include <bits/stdc++.h>
using namespace std;

class myQueue
{
public:
    list<int> l;

    void push(int val) // O(1)
    {
       l.push_back(val);
    }

    void pop() // O(1)
    {
        l.pop_front();
    }

    int front() // O(1)
    {
        return l.front();
    }

    int back() // O(1)
    {
        return l.back();
    }

    int size() // O(1)
    {
        return l.size();
    }

    bool empty() // O(1)
    {
        return l.empty();
    }
};

int main()
{
    myQueue qu;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        qu.push(val);
    }

    while (!qu.empty())
    {
        cout << qu.front() << " ";
        qu.pop();
    }

    return 0;
}