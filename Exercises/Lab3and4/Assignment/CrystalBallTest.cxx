#include <iostream>
#include <fstream>
#include <vector>
#include "CrystalBallFunction.h"

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

    // قيم مبدئية تقدري تغيّرينها لو مطلوب غيرها
    CrystalBallFunction cb(0.0, 1.0, 1.5, 2.0,
                           -5.0, 5.0, "CrystalBallTest");

    cb.integral(10000);
    cb.plotFunction();
    cb.plotData(data, 50, true);
    // ===== Metropolis sampling for Crystal Ball =====
vector<double> cb_samples =
    cb.metropolisSample(100000, 0.0, 0.5);

ofstream outCB("Assignment/Outputs/data/CrystalBallSamples.txt");
for (double s : cb_samples) {
    outCB << s << "\n";
}
outCB.close();

cb.plotData(cb_samples, 50, true);


    cout << "Done CrystalBallTest\n";
    return 0;
}
