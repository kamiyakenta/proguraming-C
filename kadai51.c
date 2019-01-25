#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define X 0
#define Y 1

int search (double p0[2], double p1[2], double p2[2]);
int straight_line(double a[2], double b[2], double c[2]);
double p3[2];

int main (void){
  int i,n;
  double p0[2];
  double p1[2];
  double p2[2];
  for(i = 0; i < 4; i++){ 
    if (i < 2) scanf("%lf", &p0[i]);
    else scanf("%lf", &p1[i-2]);
  }
  scanf("%d", &n);

  while(n > 0){
    scanf("%lf %lf", &p2[X], &p2[Y]);
    double mp01[2];
    double mp23[2];
    double p[2];
    mp01[X] = p1[X] - p0[X]; 
    mp01[Y] = p1[Y] - p0[Y];
    mp23[X]  = p2[X]  - p0[X]; 
    mp23[Y]  = p2[Y]  - p0[Y];

    if( mp01[Y] == 0 ){
        p[X] = mp23[X];
        p[Y] = -mp23[Y];
    }else{
        p[X] = ( 2*mp01[X]*mp01[Y]*mp23[Y] + mp23[X]*(pow(mp01[X],2.0) - pow(mp01[Y],2.0)) ) / ( pow(mp01[X],2.0) + pow(mp01[Y],2.0) );
        p[Y] = ( mp01[Y]*mp23[Y] + mp01[X]*mp23[X] - mp01[X]*p[X]) / mp01[Y];
    }

    p3[X] = p[X] + p0[X];
    p3[Y] = p[Y] + p0[Y];

    printf("%lf %lf\n", p3[X], p3[Y]);
    n--;
  }
  return 0;
}
