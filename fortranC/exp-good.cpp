/*program calculates exp(-x) as series
(good programming style)*/

# include <iostream>
# include <fstream>
# include <iomanip>
# include <cmath>

using namespace std;

int main() {
    const int max = 20;
    double x[max];
    double element, min, step, sum, xx, start;
    int n, i;

    // initialize
    min = 1e-10;

    start = 0.1;
    step = 0.4;

    x[0] = start;

    for (i = 1; i < max; i++) {
        x[i] = x[i-1] + step;
    }

    ofstream data("exp-good-cpp.out");
    data << setw(20) << "x-value" << setw(20) << "exp(-x)" << endl;

    // prepare summation
    for (i = 0; i < max; i++) {
        xx = x[i];
        sum = 1.0;
        element = 1.0;
        n = 0;

        // summation
        while (abs(element/sum) > min) {
            n = n + 1;
            element = element * (-xx) / static_cast<double>(n);
            sum = sum +  element;
        }

        data << scientific << setw(20) << xx << setw(20) << sum << endl;
    }

    data.close();
    cout << "data saved in exp-good-cpp.out" << endl;

    return 0;
}
