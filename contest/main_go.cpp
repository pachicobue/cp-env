#include "graph/graph.hpp"
#include "utility/md_vec.hpp"
#include "utility/printer.hpp"
#include "utility/rng.hpp"
#include "utility/scanner.hpp"

int main() {
    const auto [N, M] = in.tup<int, int>();
    const auto [S, T] = in.tup<int, int>(1, 1);
    Graph G(N);
    LOOP (M) {
        const auto [u, v] = in.tup<int, int>(1, 1);
        G.addEdge(u, v, true);
    }
    auto dp = mdVec<int>({N, N}, INF<int>);
    Queue<Pair<int, int>> Q;
    dp[S][T] = 0, Q.push({S, T});
    while (!Q.empty()) {
        const auto [u, v] = Q.front();
        Q.pop();
        for (int nu : G[u]) {
            if (nu == v) {
                continue;
            }
            if (dp[nu][v] == INF<int>) {
                dp[nu][v] = dp[u][v] + 1;
                Q.push({nu, v});
            }
        }
        for (int nv : G[v]) {
            if (nv == u) {
                continue;
            }
            if (dp[u][nv] == INF<int>) {
                dp[u][nv] = dp[u][v] + 1;
                Q.push({u, nv});
            }
        }
    }
    out.ln(dp[T][S] == INF<int> ? -1 : dp[T][S]);
    return 0;
}
