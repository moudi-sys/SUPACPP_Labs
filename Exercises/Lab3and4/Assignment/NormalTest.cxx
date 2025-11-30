#include <iostream>
#include <fstream>
#include <vector>
#include "NormalFunction.h"

using namespace std;

int main() {

    // نفس مسار ملف الداتا اللي ضبطناه في Q1
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

    // نجرّب Normal بميُو=0 وسجما=1 ومجال من -5 إلى 5
    NormalFunction nf(0.0, 1.0, -5.0, 5.0, "NormalTest");
// ==== Metropolis sampling from Normal distribution ====
std::vector<double> normal_samples =
    nf.metropolisSample(100000, 0.0, 0.5);

// Save samples to file
std::ofstream outNormal("Assignment/Outputs/data/NormalSamples.txt");
for (double s : normal_samples) {
    outNormal << s << "\n";
}
outNormal.close();

// Plot sampled data on same figure
nf.plotData(normal_samples, 50, true);

    // نرسم الدالة والبيانات
    nf.plotFunction();          // يرسم منحنى الـ Normal
    nf.plotData(data, 50, true); // يرسم الهستوقرام للبيانات

    cout << "Plot will be saved as Outputs/png/NormalTest.png (من داخل Lab3and4)\n";

    return 0;
}
