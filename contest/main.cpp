#include "utility/bin_search.hpp"
#include "utility/printer.hpp"
#include "utility/scanner.hpp"
int main() {
    const auto N = in.val<int>();
    const auto X = binSearch(N + 1, 0, [&](int x) {
        out.el("?", x);
        const auto s = in.val<Str>();
        if (s[0] == '<') {
            return true;
        } else {
            return false;
        }
    });
    out.el("!", X);

    return 0;
}
