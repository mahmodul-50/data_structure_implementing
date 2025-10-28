#include <bits/stdc++.h>
using namespace std;

class cmp
{
public:
    bool operator()(const pair<string, int>& l, const pair<string, int>& r)
    {
        if (l.first == r.first) return l.second < r.second; 
        else return l.first > r.first;
    }
};

int main()
{
    priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
    int n; cin >> n;
    while (n--)
    {
        string name; cin >> name;
        int val; cin >> val;
        pq.push({name, val});
    }
    while (!pq.empty())
    {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }
}




// edat "Status: Terminated due to timeout" dehay
// #include<bits/stdc++.h>
// using namespace std;

// class Pair
// {
//     public:
//         string name;
//         int value;
//         Pair(string name , int value)
//         {
//             this->name = name;
//             this->value = value;
//         }
// };

// class cmp
// {
//     public:
//         bool operator()(Pair l , Pair r)
//         {
//             if (l.name == r.name) return l.value < r.value;
//             else return l.name > r.name;
//         }
// };

// int main()
// {
//     priority_queue<Pair , vector<Pair> , cmp> pq;
//     int n; cin >> n;
//     while(n--)
//     {
//         string name; cin >> name;
//         int val; cin >> val;
//         Pair x(name , val);
//         pq.push(x);
//     }
//     while(!pq.empty())
//     {
//         cout << pq.top().name << " " << pq.top().value <<endl;
//         pq.pop();
//     }
// }