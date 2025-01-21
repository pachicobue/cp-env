#include "utility/printer.hpp"
#include "utility/rng.hpp"
int main() {
    const auto N = rng.val(2, 1000);
    const auto X = rng.val(1, N);
    out.ln(N, X);
    return 0;
}
