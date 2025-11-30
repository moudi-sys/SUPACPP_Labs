#ifndef NORMALFUNCTION_H
#define NORMALFUNCTION_H

#include <string>
#include "../FiniteFunctions.h"

// كلاس Normal يرث من FiniteFunction
class NormalFunction : public FiniteFunction {
public:
    // constructor يحدد الميو والسجما ومجال الرسم واسم ملف الصورة
    NormalFunction(double mean, double sigma,
                   double rmin, double rmax,
                   const std::string &outname);

    // نعيد تعريف الدالة f(x) لتكون دالة Normal
    double callFunction(double x) override;

private:
    double m_mean;
    double m_sigma;
};

#endif
