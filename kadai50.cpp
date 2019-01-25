#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double xp1, yp1, xp2, yp2;
    cin >> xp1 >> yp1 >> xp2 >> yp2;
    double a = (yp2-yp1) / (xp2-xp1);
    double b = yp1 - a * xp1;

    int n;
    double px, py; 
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> px >> py;
        double x = (a * (py - b) + px) / (a*a + 1);
        double y = a * (a * (py - b) + px) / (a*a + 1) + b;
        
        cout << setprecision(10)
             << fixed
             << x << " " << y
             << endl;
    }
}

