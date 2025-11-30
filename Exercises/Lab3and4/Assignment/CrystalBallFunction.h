#ifndef CRYSTALBALLFUNCTION_H
#define CRYSTALBALLFUNCTION_H

#include <string>
#include "../FiniteFunctions.h"

// Crystal Ball distribution = Gaussian core + power-law tail
class CrystalBallFunction : public FiniteFunction {
public:
    CrystalBallFunction(double mean, double sigma,
                        double alpha, double n,
                        double rmin, double rmax,
                        const std::string &outname);

    double callFunction(double x) override;

private:
    double m_mean;
    double m_sigma;
    double m_alpha;
    double m_n;
};

#endif
