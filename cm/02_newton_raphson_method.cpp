#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

double f(double x) { return (x * x * x * x) - (x)-10; }

double df(double x) { return (4 * x * x * x) - 1; }

int main() {

  int itr, maxitr;

  float h, x0, x1, aerr;

  cout << "Enter x0, allowed error, maximum iterations : " << endl;
  cin >> x0 >> aerr >> maxitr;
  cout << fixed;

  for (itr = 1; itr <= maxitr; itr++) {
    h = f(x0) / df(x0);
    x1 = x0 - h;
    cout << "Iteration no. " << itr << ", x = " << x1 << endl;
    if (fabs(h) < aerr) {
      cout << "After no. " << itr << "iterations, root = " << x1 << endl;
      cout << "Ritvik Bansal CST" << endl;
      return 0;
    }
    x0 = x1;
  }

  cout << "Iterations not sufficient, solution does not converge" << endl;
  cout << "Aditya Gupta CSE9" << endl;
  return 1;
}
