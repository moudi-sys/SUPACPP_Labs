#include "CrystalBallFunction.h"
#include <cmath>

CrystalBallFunction::CrystalBallFunction(double mean, double sigma,
                                         double alpha, double n,
                                         double rmin, double rmax,
                                         const std::string &outname)
    : m_mean(mean), m_sigma(sigma), m_alpha(alpha), m_n(n)
{
    setRangeMin(rmin);
    setRangeMax(rmax);
    setOutfile(outname);
}

// Crystal Ball shape (normalisation handled numerically)
double CrystalBallFunction::callFunction(double x)
{
    double t = (x - m_mean) / m_sigma;
    double absAlpha = std::fabs(m_alpha);

    if (t > -absAlpha) {
        // Gaussian region
        return std::exp(-0.5 * t * t);
    }
    else {
        // Power-law tail
        double A = std::pow(m_n / absAlpha, m_n) * std::exp(-0.5 * absAlpha * absAlpha);
        double B = m_n / absAlpha - absAlpha;
        return A * std::pow(B - t, -m_n);
    }
}
