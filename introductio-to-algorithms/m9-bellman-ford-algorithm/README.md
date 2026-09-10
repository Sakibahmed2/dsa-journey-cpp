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

class Edge {
public:
    int u, v, w;
    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

const int INF = 1e9;

int main() {
    int V = 4;
    vector<Edge> edgeList; // all graph edges

    edgeList.push_back(Edge(0, 1, 5));
    edgeList.push_back(Edge(0, 2, 10));
    edgeList.push_back(Edge(1, 3, 3));
    edgeList.push_back(Edge(2, 1, -4));
    edgeList.push_back(Edge(3, 2, 2));

    vector<int> dist(V, INF);
    dist[0] = 0; // source = 0

    // Pass 1 to V-1 : relax all edges
    for (int i = 1; i <= V - 1; i++) {
        for (Edge ed : edgeList) {
            if (dist[ed.u] != INF && dist[ed.u] + ed.w < dist[ed.v]) {
                dist[ed.v] = dist[ed.u] + ed.w;
            }
        }
    }

    // Pass V : negative cycle detection
    bool hasNegativeCycle = false;
    for (Edge ed : edgeList) {
        if (dist[ed.u] != INF && dist[ed.u] + ed.w < dist[ed.v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        cout << "Negative cycle exists! No shortest path.\n";
    } else {
        for (int i = 0; i < V; i++) {
            cout << "dist[" << i << "] = " << dist[i] << "\n";
        }
    }
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
