#include "utility/printer.hpp"
#include "utility/rng.hpp"

int main() {
    out.ln(1);
    const auto N = 200;
    out.ln(N);
    for (int x : irange(-100, 100)) {
        for (int y : irange(0, 1)) {
            out.ln(x, y, 1000);
        }
    }

    return 0;
}
