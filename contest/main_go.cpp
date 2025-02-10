#include "utility/printer.hpp"
#include "utility/rng.hpp"
#include "utility/scanner.hpp"

int main() {
    const auto [A, B] = in.tup<int, int>();
    out.ln(A + B);
    return 0;
}
