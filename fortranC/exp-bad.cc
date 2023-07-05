/*program calculates exp(-x) as series
(bad programming style)*/

# include <iostream>
# include <fstream>
# include <iomanip>
# include <cmath>

using namespace std;

int main(){
    const int max = 20; 
    int i, j, k, kwrite;
    double x[max];
    double down, min, step, sum, up, xx, start;
    
    // initialize
    min  = 1e-10;

    start= 0.1e0;
    step = 0.4e0;

    x[0] = start;

    for (int i = 1; i < max; i++){
        x[i] = x[i-1] + step;
    }

    // the file to write everything in
    ofstream data("exp-bad-cpp.out");
    data << setw(20) << "x-value" << setw(20) << "exp(-x)" << endl;

    for (int k = 0; k < max; k++){
        xx = x[k];

        sum = 1.0;
        i = 0;
        down = 1.0;
        up = 1.0;

        while (abs((up/down)/sum) > min){
            i = i + 1;
            down = 1.0;
            up = 1.0;

            for (int j = 1; j <= i; j++){
                up = -up * xx;
                down = down * j;
            }
            sum = sum + up/down;
        }

        data << scientific << setw(20) << xx << setw(20) << sum << endl;
    }
    
    cout << "data saved in exp-bad-cpp.out" << endl;

    data.close();
    return 0;
}
