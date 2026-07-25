#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<string> l;

    string s;
    while (cin >> s && s != "end")
    {
        l.push_back(s);
    }

    auto current = l.begin();

    int t;
    cin >> t;

    while (t--)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "visit")
        {
            string address;
            cin >> address;

            auto it = find(l.begin(), l.end(), address);

            if (it == l.end())
            {
                cout << "Not Available" << endl;
            }
            else
            {
                current = it;
                cout << *current << endl;
            }
        }
        else if (cmd == "next")
        {
            auto temp = current;
            temp++;

            if (temp == l.end())
            {
                cout << "Not Available" << endl;
            }
            else
            {
                current++;
                cout << *current << endl;
            }
        }
        else if (cmd == "prev")
        {
            if (current == l.begin())
            {
                cout << "Not Available" << endl;
            }
            else
            {
                current--;
                cout << *current << endl;
            }
        }
    }

    return 0;
}

// Theoretical Question Explanation:

// Question Analysis:
// আমাকে একটি browser history-এর মতো address list দেওয়া হবে।
// প্রথমে সবগুলো address list a store করতে হবে।
// তারপর Q টি query দেওয়া হবে। প্রতিটি query অনুযায়ী visit, next এবং prev command execute করতে হবে।
// যদি visit command আসে, তাহলে address টি list-এ আছে কিনা check করতে হবে। থাকলে সেই address-এ যেতে হবে, না থাকলে "Not Available" print করতে হবে।
// Next এবং Prev command ব্যবহার করে current position থেকে সামনে অথবা পিছনে move করতে হবে।

// Observation:
// Visit command আসলে পুরো list-এ address টি search করতে হবে।
// যদি address টি পাওয়া যায়, তাহলে current iterator update করে সেই address-এ নিয়ে যেতে হবে।
// আর যদি address টি না পাওয়া যায়, তাহলে current position পরিবর্তন হবে না, শুধু "Not Available" print করতে হবে।
// Next অথবা Prev এ যাওয়ার আগে check করতে হবে move করা সম্ভব কিনা।
// যদি move করা সম্ভব না হয়, তাহলে current position আগের জায়গাতেই থাকবে এবং "Not Available" print করতে হবে।

// Testcase Analysis:
// Example List:
// facebook google youtube

// শুরুতে Current = facebook

// Query:
// visit google
// Current → google

// Query:
// prev
// Current → facebook

// Query:
// next
// Current → google

// Query:
// visit instagram
// Instagram list-এ নেই, তাই "Not Available" print হবে।
// Current position পরিবর্তন হবে না, google-এই থাকবে।