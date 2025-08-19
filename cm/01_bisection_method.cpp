#include <cmath>
#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

double f(double x) { return pow(x, 3) - 4 * x - 9; }

int main() {
  double x0, x1, x, f0, f1, f_, e;

  int step = 1;

  cout << setprecision(6) << fixed;
up:
  cout << "Enter first guess: ";
  cin >> x0;
  cout << "Enter second guess: ";
  cin >> x1;
  cout << "Enter tolerable error:";
  cin >> e;

  f0 = f(x0);
  f1 = f(x1);

  if (f0 * f1 > 0.0) {
    cout << "Incorrect initial guess" << endl;
    goto up;
  }

  cout << endl << "===" << endl;
  cout << "Bisection Method" << endl;
  do {
    x = (x0 + x1) / 2;
    f_ = f(x);
    cout << "Iteration -" << step << ":\t=" << setw(10) << x
         << "and f(x) = " << setw(10) << f(x) << endl;

    if (f0 * f_ < 0) {
      x1 = x;
    } else {
      x0 = x;
    }

    step++;
  } while ((x1 - x0) >= e);

  cout << endl << "Root is: " << x << endl;
  cout << "ADITYA GUPTA" << endl;
  return 0;
app store}
