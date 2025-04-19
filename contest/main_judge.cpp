#include <fstream>

#include "internal.hpp"
#include "utility/modint.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"

void special(const char* input_file_name, const char* output_file_name) {
    std::ifstream fi(input_file_name);
    std::ifstream fo(output_file_name);
    Scanner in{fi}, out{fo};
    Printer err{std::cerr};

    auto check = [&] {
        const auto N = in.val<i64>();
        const auto [A, M] = out.tup<i64, i64>();
        assert(1 <= A && A <= TEN<i64>(18));
        assert(1 <= M && M <= TEN<i64>(18));
        using mint = modint_dynamic<0>;
        mint::setMod(M);
        assert(mint(A).pow(N) == 1);
    };
    const auto T = in.val<int>();
    LOOP (T) {
        check();
    }
}

void reactive(const char* input_file_name) {
    std::ifstream fi{input_file_name};
    Scanner in{fi};
    Printer err{std::cerr};

    const auto N = in.val<int>();
    const auto Ps = in.vec<int>(N);
    const auto As = in.vec<i64>(N);
    out.el(N), err.el("[out]", N);
    Vec<i64> Ss(N + 1);
    for (int i : rep(N)) {
        Ss[i + 1] = Ss[i] + As[i];
    }
    auto sum = [&](int s, int t) {
        return Ss[t] - Ss[s];
    };
    const int Q = N * 2;
    int QN = 0;
    while (true) {
        const auto c = in.val<char>();
        if (c == '?') {
            QN += 1;
            assert(QN <= Q);
            auto [s, t] = in.tup<int, int>();
            err.el("[in]", "?", s, t);
            assert(s != t);
            assert(1 <= s && s <= N);
            assert(1 <= t && t <= N);
            s--, t--;
            int l = Ps[s], r = Ps[t];
            if (l > r) {
                std::swap(l, r);
            }
            r++;
            out.el(sum(l, r)), err.el("[out]", sum(l, r));
        } else {
            auto ps = in.vec<int>(N);
            auto as = in.vec<i64>(N);
            err.el("[in]", "!", ps, as);
            mdSeqPlus(ps, -1);
            assert(Ps == ps);
            assert(As == as);
            break;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc == 3) {
        special(argv[1], argv[2]);
    } else if (argc == 2) {
        reactive(argv[1]);
    } else {
        assert(false);
    }
    return 0;
}
