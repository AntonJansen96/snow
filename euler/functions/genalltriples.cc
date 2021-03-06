#include "../euler.h"
#include <cmath>
#include <tuple>

// Generate all Pythagorean triples with perimeter (a + b + c) < perimLim.
// Contains duplicate perimeters.
std::tuple<std::vector<size_t>, std::vector<size_t>, std::vector<size_t>> 
euler::genTriples(size_t perimLim)
{
    std::vector<size_t> A, B, C;
    size_t a, b, c, k;

    for (size_t m = 1; m < sqrt(perimLim); ++m)
        for (size_t n = m + 1; n < sqrt(perimLim); ++n)
            if (!(m & 1 && n & 1) && isCoprime(m, n))
            {
                a = n*n - m*m;
                b = 2 * m * n;
                c = n*n + m*m;

                k = 1;
                while (k * (a + b + c) <= perimLim)
                {
                    A.push_back(k * a);
                    B.push_back(k * b);
                    C.push_back(k * c);

                    ++k;
                }
            }

    return std::tuple{A, B, C};
}
