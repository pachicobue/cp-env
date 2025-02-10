#include "utility/printer.hpp"
#include "utility/rng.hpp"

int main() {
    constexpr int N = 1000;
    const auto As = iotaVec(N, 1);
    out.ln(N);
    out.ln(As);
    return 0;
}
