#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// f(x) = 1 / (1 + x^2)
double f(double x) {
    return 1.0 / (1.0 + x * x);
}

int main() {
    // مسار ملف الداتا من داخل مجلد Assignment
    string filename = "Assignment/Outputs/data/MysteryData14235.txt";


    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Error: could not open file " << filename << endl;
        return 1;
    }

    vector<double> data;
    double x;

    // نقرأ كل قيم x من ملف الداتا
    while (infile >> x) {
        data.push_back(x);
    }

    cout << "Read " << data.size() << " data points\n";

    // نكتب x و f(x) في ملف جديد
    ofstream outfile("function_values.txt");
    if (!outfile.is_open()) {
        cerr << "Error: could not open output file function_values.txt\n";
        return 1;
    }

    for (double val : data) {
        outfile << val << " " << f(val) << "\n";
    }

    cout << "Saved function values to function_values.txt\n";

    return 0;
}