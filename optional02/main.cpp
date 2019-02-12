#include <optional>
#include <iostream>
#include <complex>

int main()
{
    std::optional<int> oi { 10 };
    std::optional d { 10 };

    // make_optional
    auto od = std::make_optional(3.0);
    auto oc = std::make_optional<std::complex<double>>(3.0, 4.0);

    std::optional<std::complex<double>> o7 { std::in_place, 3.0, 4.0 };

    return 0;
}

