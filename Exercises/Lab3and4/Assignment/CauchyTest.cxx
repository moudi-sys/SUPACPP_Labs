#include <iostream>
#include <fstream>
#include <vector>
#include "CauchyFunction.h"

using namespace std;

int main() {

    string filename = "Assignment/Outputs/data/MysteryData14235.txt";
    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Error: could not open file " << filename << endl;
        return 1;
    }

    vector<double> data;
    double x;
    while (infile >> x) {
        data.push_back(x);
    }
    cout << "Read " << data.size() << " data points\n";

    // قيم مبدئية
    CauchyFunction cf(0.0, 1.0, -5.0, 5.0, "CauchyTest");

    cf.integral(10000);      // للتطبيع
    cf.plotFunction();
    cf.plotData(data, 50, true);

    // ===== Metropolis sampling (مرّة وحدة بس) =====
    vector<double> cauchy_samples =
        cf.metropolisSample(100000, 0.0, 0.5);

    ofstream outCauchy("Assignment/Outputs/data/CauchySamples.txt");
    for (double s : cauchy_samples) {
        outCauchy << s << "\n";
    }
    outCauchy.close();

    cf.plotData(cauchy_samples, 50, true);

    cout << "Done CauchyTest (الصورة في Outputs/png/CauchyTest.png)\n";
    return 0;
}
