#include <iostream>
#include <cmath>

using namespace std;

void givemek(double* , double , double , double , const double , const double , const double );

int main(void){
  const double T = 100;
  const double dt = 0.001;
  const double a = 10;
  const double b = 28;
  const double c = 8/3.0;
  double x=1, y=1, z=1;
  double k[4][3];
  double temp[3];
  
  cout << 0 << "\t" << x << "\t" << y << "\t" << z << endl;
  
  for (double t=dt; t <= T; t+=dt){
    givemek(k[0], x, y, z, a, b, c);
    
    temp[0] = x + dt/2.0 * k[0][0];
    temp[1] = y + dt/2.0 * k[0][1];
    temp[2] = z + dt/2.0 * k[0][2];
    givemek(k[1], temp[0], temp[1], temp[2], a, b, c);
    
    temp[0] = x + dt/2.0 * k[1][0];
    temp[1] = y + dt/2.0 * k[1][1];
    temp[2] = z + dt/2.0 * k[1][2];
    givemek(k[2], temp[0], temp[1], temp[2], a, b, c);
    
    temp[0] = x + dt * k[2][0];
    temp[1] = y + dt * k[2][1];
    temp[2] = z + dt * k[2][2];
    givemek(k[3], temp[0], temp[1], temp[2], a, b, c);
    
    x += dt / 6.0 * (k[0][0] + 2*k[1][0] + 2*k[2][0] + k[3][0]);
    y += dt / 6.0 * (k[0][1] + 2*k[1][1] + 2*k[2][1] + k[3][1]);
    z += dt / 6.0 * (k[0][2] + 2*k[1][2] + 2*k[2][2] + k[3][2]);
    cout << t << "\t" << x << "\t" << y << "\t" << z << endl;
  }
return 0;
}

void givemek(double* k, double x, double y, double z, const double a, const double b, const double c) {
  k[0] = a * (y-x);
  k[1] = x * (b-z) - y;
  k[2] = x*y - c*z;
}  