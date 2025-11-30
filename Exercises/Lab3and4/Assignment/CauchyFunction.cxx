#include "CauchyFunction.h"
#include <cmath>

CauchyFunction::CauchyFunction(double x0, double gamma,
                               double rmin, double rmax,
                               const std::string &outname)
  : m_x0(x0), m_gamma(gamma)
{
    setRangeMin(rmin);
    setRangeMax(rmax);
    setOutfile(outname);
}

// Cauchy / Lorentzian PDF
double CauchyFunction::callFunction(double x) {
    double dx = x - m_x0;
    return (1.0 / M_PI) * (m_gamma / (dx*dx + m_gamma*m_gamma));
}
