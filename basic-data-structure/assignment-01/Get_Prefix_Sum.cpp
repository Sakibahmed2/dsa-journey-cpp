#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        v[i] = x + v[i - 1];
    }

    for (int i = v.size() - 1; i > 0; i--)
    {
        cout << v[i] << " ";
    }

    return 0;
}

//  Theoretical Question Explanation:

//  Question analysis:
//  একটি array দেওয়া হবে যার prefix sum বের করে reverse এ print করতে হবে।

//  Observation:
//  নতুন কোনো vector declare না করে একই vector এ input নেওয়ার সময় previous value এর সাথে নতুন value যোগ করে দিয়েছি।
//  Vector এর size এক বেশি নেওয়া হয়েছে যাতে 1 index থেকে শুরু করলে তার আগের 0th index এ 0 value থাকে।
//  আর print করার সময় শুধু array টাকে উল্টো করে print করে দিয়েছি।

//  Test case analysis:
//  আমার test case এর জন্য explanation.

//  Example Input:
//  3
//  6 7 1

//  v = {0, 0, 0, 0};
//  v = {0, 0 + 6, 6 + 7, 13 + 1};
//  v = {0, 6, 13, 14}

//  Print করার সময় উল্টো করে print করে দিলেই done.
//  যেমন: {14, 13, 6} // v.size() - 1 থেকে শুরু করে।