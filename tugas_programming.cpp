#include <iostream>
#include <cmath>

using namespace std;

int L_1 = 0;
int L_2 = 0;
double sudut_1 = 0;
double sudut_2 = 0;
double sudut_total;

double x_1;
double y_1;
double x_2;
double y_2;
double x;
double y;

int main() {
    cout << "input nilai L_1: ";
    cin >> L_1;
    cout << "input nilai L_2: ";
    cin >> L_2;
    cout << "input nilai sudut_1: ";
    cin >> sudut_1;
    cout << "input nilai sudut_2: ";
    cin >> sudut_2;

    sudut_total = sudut_1 + sudut_2;

    x = L_1 * cos(sudut_1 * (M_PI / 180.0)) + L_2 * cos(sudut_total * (M_PI / 180.0));
    y = L_1 * sin(sudut_1 * (M_PI / 180.0)) + L_2 * sin(sudut_total * (M_PI / 180.0));

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    return 0;
}
