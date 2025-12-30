#include "utility/md_vec.hpp"
#include "utility/printer.hpp"
#include "utility/rng.hpp"

int main() {
    const auto N = rng.val(3, 3);
    out.ln(N);
    LOOP (N) {
        LOOP (N) {
            out.ln(rng.vec(N, 0, 1));
        }
    }
    return 0;
}
