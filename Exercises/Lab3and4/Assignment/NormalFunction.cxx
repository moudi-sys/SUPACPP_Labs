#include "NormalFunction.h"
#include <cmath>

// constructor
NormalFunction::NormalFunction(double mean, double sigma,
                               double rmin, double rmax,
                               const std::string &outname)
  : m_mean(mean), m_sigma(sigma)
{
    // نستخدم setRange.. من كلاس الأب
    setRangeMin(rmin);
    setRangeMax(rmax);
    setOutfile(outname);
}

// دالة الـ Normal:  (1 / (sqrt(2π) σ)) * exp(-(x-μ)^2 / (2 σ^2))
double NormalFunction::callFunction(double x) {
    double z = (x - m_mean) / m_sigma;
    double norm = 1.0 / (std::sqrt(2.0 * M_PI) * m_sigma);
    return norm * std::exp(-0.5 * z * z);
}
