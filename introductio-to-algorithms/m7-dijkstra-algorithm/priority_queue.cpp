#include <bits/stdc++.h>
using namespace std;

int main()
{
    // priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(2);
    pq.push(5);
    pq.push(1);
    cout << pq.top() << endl;
    pq.push(10);
    cout << pq.top() << endl;
    pq.pop();
    pq.pop();
    cout << pq.top() << endl;

    return 0;
}