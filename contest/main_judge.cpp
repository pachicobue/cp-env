#include <cstdio>
#include <filesystem>
#include <fstream>
#include "utility/printer.hpp"
#include "utility/scanner.hpp"

int main(int argc, char* argv[]) {
    assert(argc == 2);
    std::ifstream f1(argv[1]);
    Scanner in1{f1};
    Printer err{std::cerr};
    const auto [N, X] = in1.tup<int, int>();
    out.el(N);
    err.el("[out]", N);
    constexpr int Q = 10;
    int QN = 0;
    while (true) {
        const auto c = in.val<char>();
        if (c == '?') {
            QN += 1;
            assert(QN <= Q);
            const auto x = in.val<int>();
            err.el("[in]", "?", x);
            out.el(x < X ? "<" : ">=");
            err.el("[out]", (x < X ? "<" : ">="));
        } else {
            const auto Y = in.val<int>();
            err.el("[in]", "!", Y);
            assert(Y == X);
            break;
        }
    }
    return 0;
}
