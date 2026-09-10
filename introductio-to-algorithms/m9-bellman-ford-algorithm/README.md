# 🔔 Bellman-Ford Algorithm

## 📌 What is Bellman-Ford?

Bellman-Ford is a **single-source shortest path** algorithm that finds the shortest
distance from a **source node** to **all other nodes** in a weighted graph.

> The catch: it can work with **negative weight edges** — which Dijkstra **cannot**.

---

## ⚙️ Core Idea: Edge Relaxation

For every edge `(u → v)` with weight `w`:

```
if dist[u] + w < dist[v]:
    dist[v] = dist[u] + w
```

- Start: `dist[source] = 0`, all others = `INFINITY`.
- Repeat the relaxation for **ALL edges**, **V - 1 times**.
- Why `V - 1`? In the worst case, the shortest path uses at most `V - 1` edges
  (no repeating a node). So `V - 1` full passes guarantee the answer.

---

## 💡 Definition (One Liner)

> **Bellman-Ford** = an algorithm that finds the shortest path from one source to
> all nodes in `O(V × E)` time, and can handle **negative edges** and even
> **detect negative cycles**.

---

## ❓ Why do we need it? Why not Dijkstra / BFS / DFS?

| Algorithm           | Best for                                                          | Limitation                                        |
| ------------------- | ----------------------------------------------------------------- | ------------------------------------------------- |
| **BFS**             | Shortest path of **unweighted** graph                             | Cannot handle weights at all                      |
| **Dijkstra**        | Shortest path with **positive** weights                           | ❌ Fails / gives wrong answer with negative edges |
| **DFS**             | Exploring paths, connectivity, cycles                             | Not for shortest path at all                      |
| **Bellman-Ford** ✅ | Shortest path with **negative** weights + detects negative cycles | Slower: `O(V × E)`                                |

**Why not Dijkstra?**
Dijkstra greedily picks the closest unvisited node and assumes a visited node can
never get a better distance later. A **negative edge** can break that assumption
(another node may later offer a shortcut), so Dijkstra gives the **wrong answer**.

**Why not BFS?**
BFS counts edges, not edge weights. With weights, BFS doesn't know the cost.

**Why not DFS?**
DFS just explores; it never guarantees the minimum cost path.

---

## 🔍 Negative Cycle Detection (The Special Power)

A **negative cycle** = a cycle whose total weight is **negative**.

- Run relaxation **one extra time** (the `V`-th pass).
- If **any** edge still relaxes → a negative cycle exists.
- With a negative cycle, the shortest path is **undefined**
  (you can loop forever and keep getting smaller distance).

```
run relaxation V - 1 times
run relaxation 1 more time
if any edge relaxes:
    print("Negative cycle exists!")
```

---

## 📋 Algorithm Steps (Recap)

1. Set `dist[source] = 0`, rest = `INF`.
2. Repeat `V - 1` times:
   - For each edge `(u, v, w)`: relax it.
3. (Optional) Run pass #`V` to detect negative cycle.
4. If no negative cycle → `dist[]` = shortest distances.

---

## ⏱️ Complexity

|           |            |
| --------- | ---------- |
| **Time**  | `O(V × E)` |
| **Space** | `O(V)`     |

> Dijkstra: `O((V + E) log V)`. So Bellman-Ford is slower but more **general**.

---

## 📌 When to use / not use

✅ **Use Bellman-Ford when:**

- Graph has **negative weight edges**.
- You need to **detect a negative cycle**.
- Graph is dense but `V` is small (e.g. competitive problems with `V ≤ 1000`).

❌ **Avoid when:**

- All weights are positive → use **Dijkstra** (faster).
- Graph is unweighted → use **BFS**.
- `V × E` too large → too slow.

---

## 💻 Core Code (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int n, e;
int dis[1005];
vector<Edge> edge_list;

void bellman_ford()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            int a, b, c;
            a = ed.a;
            b = ed.b;
            c = ed.c;

            if (dis[a] != INT_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
            }
        }
    }

    bool flag = false;
    for (auto ed : edge_list)
    {
        int a, b, c;
        a = ed.a;
        b = ed.b;
        c = ed.c;

        if (dis[a] != INT_MAX && dis[a] + c < dis[b])
        {
            flag = true;
            break;
        }
    }

    if (flag)
        cout << "Negative weighted cycle detected" << endl;
    else
    {
        cout << "No cycle detected" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << i << " -> " << dis[i] << endl;
        }
    }
}

int main()
{

    cin >> n >> e;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
        // edge_list.push_back(Edge(b, a, c)); // If undirected graph
    }

    for (int i = 0; i < n; i++)
        dis[i] = INT_MAX;

    dis[0] = 0;

    bellman_ford();

    return 0;
}
```

---

## 🎯 One-Line Takeaways

- **Relax all edges V-1 times** → shortest distances.
- **1 extra pass** → negative cycle detector.
- **Handles negative edges** → Dijkstra can't.
- `O(V × E)` time, `O(V)` space.

> ⚠️ Interesting: for a graph like the one in the code (with edge `2 → 1` = -4),
> shortest paths still work fine **as long as there is NO negative cycle**.
