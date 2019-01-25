#include <iostream>
#include <cmath>

using namespace std;

struct Vector{
  double x;
  double y;
};

double norm(Vector p){
  return p.x*p.x + p.y*p.y;
}

double outer_prod(Vector p1, Vector p2){
  return p1.x*p2.y - p1.y*p2.x;
}

bool is_parallel(Vector p1, Vector p2){
  return outer_prod(p1, p2)==0 ? true : false;
}

int main(){
  double a, b, c, d;
  cin >> a >> b >> c >> d;
  Vector v1, v2;
  v1.x = c - a;
  v1.y = d - b;

  int num;
  cin >> num;

  for(int i=0; i<num; i++){
    double x, y;
    cin >> x >> y;
    v2.x = x - a;
    v2.y = y - b;

    if(is_parallel(v1, v2)){
      if(fabs(v1.x + v2.x) < fabs(v1.x) + fabs(v2.x)
      || fabs(v1.y + v2.y) < fabs(v1.y) + fabs(v2.y))
        cout << "ONLINE_BACK";
      else if(norm(v1) < norm(v2))
        cout << "ONLINE_FRONT";
      else 
        cout << "ON_SEGMENT";
    }
    else{
      if(outer_prod(v1, v2) > 0)
        cout << "COUNTER_CLOCKWISE";
      else
        cout << "CLOCKWISE";
    }
    cout << endl;
  }
}