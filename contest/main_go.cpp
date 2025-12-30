#include "utility/md_vec.hpp"
#include "utility/modint.hpp"
#include "utility/printer.hpp"
#include "utility/rng.hpp"
#include "utility/scanner.hpp"

int main() {
    using mint = modint_998244353;
    const auto N = in.val<int>();
    auto Ass = mdVec<mint>({N, N, N});
    for (int i : rep(N)) {
        for (int j : rep(N)) {
            for (int k : rep(N)) {
                Ass[i][j][k] = in.val<mint>();
            }
        }
    }
    Vec<mint> Ans(N, 0);
    Vec<int> st;
    Fix([&](auto self, int t, int x, mint w, Vec<int>& st) -> void {
        if (t == N) {
            Ans[x] += w;
            return;
        }
        for (int y : rep(N)) {
            const mint nw = w * Ass[t][x][y];
            const int nx = y;
            st.push_back(x);
            self(t + 1, nx, nw, st);
            st.pop_back();
        }
        if (!st.empty()) {
            const int top = st.back();
            const mint nw = w * Ass[t][x][top];
            const int nx = (x + top) % N;
            st.pop_back();
            self(t + 1, nx, nw, st);
            st.push_back(top);
        }
    })(0, 0, 1, st);
    for (int i : rep(N)) {
        out.ln(Ans[i]);
    }
    return 0;
}
