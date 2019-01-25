#include <iostream>
#include <cmath>

using namespace std;

struct Vector{
  double x;
  double y;
};

double norm(Vector v){
  return v.x*v.x + v.y*v.y;
}

int inner_prod(Vector v1, Vector v2){
  return v1.x*v2.x + v1.y*v2.y;
}

int outer_prod(Vector v1, Vector v2){
  return v1.x*v2.y - v1.y*v2.x;
}

bool is_vertical(Vector v1, Vector v2){
  return inner_prod(v1, v2)==0 ? true : false;
}

bool is_parallel(Vector v1, Vector v2){
  return outer_prod(v1, v2)==0 ? true : false;
}

int main(){
  Vector v1, v2;

  int num;
  cin >> num;

  for(int i=0; i<num; i++){
    int Xp0, Yp0, Xp1, Yp1, Xp2, Yp2, Xp3, Yp3;
    cin >> Xp0 >> Yp0 >> Xp1 >> Yp1;
    v1.x = Xp1 - Xp0;
    v1.y = Yp1 - Yp0;

    cin >> Xp2 >> Yp2 >> Xp3 >> Yp3;
    v2.x = Xp3 - Xp2;
    v2.y = Yp3 - Yp2;

    if(is_parallel(v1, v2))
      cout << 2;
    else if(is_vertical(v1, v2))
      cout << 1;
    else
      cout << 0;

    cout << endl;
  }
}