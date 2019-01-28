#include <iostream>
#include <cmath>
#include <stdbool.h>
#include <stdio.h>

using namespace std;

struct Vector{
  double x;
  double y;
};

struct Line{
  Vector points[2]; 
};

double EPS = 1e-10;

double len(Vector a) {
  return pow(a.x * a.x + a.y * a.y, 0.5);
}

double dot(Vector a, Vector b) {
  return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b) {
  return a.x * b.y - a.y * b.x;
}

int ccw(Vector p, Vector q, Vector r) {
  Vector a = {q.x - p.x, q.y - p.y};
  Vector b = {r.x - p.x, r.y - p.y};
  if(cross(a, b) > EPS) return 1;
  if(cross(a, b) < -EPS) return -1;
  if(dot(a, b) < -EPS) return 2;
  if (dot(a, a) < dot(b, b)) return -2;
  return 0;
}

Vector toVec(Line s) {
  Vector tV = {s.points[1].x - s.points[0].x, s.points[1].y - s.points[0].y};
  return tV;
}

Vector toVecInverse(Line s) {
  Vector tVI = {s.points[0].x - s.points[1].x, s.points[0].y - s.points[1].y};
  return tVI;
}

int sign(double a) {
  if(a > EPS) return 1;
  if(a < -EPS) return -1;    
  return 0;
}

bool ok(Line a, Line b) {
    return ccw(a.points[0], a.points[1], b.points[0]) * ccw(a.points[0], a.points[1], b.points[1]) <= 0;
  }

// 二つの線分の交差判定
bool iss(Line s, Line t) {
  return ok(s, t) && ok(t, s);
}

// 点と直線の距離
double dlp(Line l, Vector p) {
  Vector tmp = {p.x - l.points[0].x, p.y - l.points[0].y};
  return abs(cross(toVec(l), tmp)) / len(toVec(l));
}

// 点と線分の距離
double dsp(Line s, Vector p) {
  Vector a = {p.x - s.points[0].x, p.y - s.points[0].y};
  Vector b = {p.x - s.points[1].x, p.y - s.points[1].y};
  if(sign(dot(toVec(s), a)) <= 0) return len(a);
  if(sign(dot(toVecInverse(s), b)) <= 0) return len(b);
  return dlp(s, p);
}

// 線分と線分の距離
double dss(Line s, Line t){
  double tmp[4] = {dsp(s, t.points[0]), dsp(s, t.points[1]), dsp(t, s.points[0]), dsp(t, s.points[1])};
    double min = tmp[0];
    for(int i = 0; i < 4; i++) {
      if(tmp[i] < min) min = tmp[i];
    }
    return iss(s, t) ? 0.0 : min;
}

int main(void){
  int n;
  scanf("%d", &n);
  while(n > 0){
    Vector p0, p1, p2, p3;
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &p0.x, &p0.y, &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y);
    Line a, b;
    a.points[0] = p0;
    a.points[1] = p1;
    b.points[0] = p2;
    b.points[1] = p3;
    printf("%.10f\n", dss(a, b));
    n--;
  }
  return 0;
}
