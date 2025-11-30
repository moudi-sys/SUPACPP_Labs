#ifndef CAUCHYFUNCTION_H
#define CAUCHYFUNCTION_H

#include <string>
#include "../FiniteFunctions.h"

// Cauchy / Lorentz distribution
class CauchyFunction : public FiniteFunction {
public:
    // x0 = المركز, gamma = الــ width (scale)
    CauchyFunction(double x0, double gamma,
                   double rmin, double rmax,
                   const std::string &outname);

    // f(x) = 1/pi * gamma / ((x-x0)^2 + gamma^2)
    double callFunction(double x) override;

private:
    double m_x0;
    double m_gamma;
};

#endif
