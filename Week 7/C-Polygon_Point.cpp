// Taimur Azhar z5116684
// Prog Chal
// Week 6 Problem C - Polygon Point Containtment

#include <stdlib.h>
#include <iostream>
#include <math.h>

#define limit 10100
#define magicx 10007
#define magicy 10009

#define SHOW(X) cout << # X " = " << (X) << endl;

using namespace std;
/*
 * cross product
 */
const double EPS = 1e-8;
typedef pair<double, double> pt;
#define x first
#define y second

pt operator-(pt a, pt b) {
  return pt(a.x - b.x, a.y - b.y);
}

bool zero(double x) {
  return fabs(x) <= EPS;
}

double cross(pt a, pt b) {
  return a.x*b.y - a.y*b.x;
}

bool ccw(pt a, pt b, pt c) {
  return cross(b - a, c - a) >= 0;
}
/*
 * segment segment intersection
 */
typedef pair<pt, pt> seg;
#define a first
#define b second

bool collinear(seg a, seg b) { // all four points collinear

  return zero(cross(a.b - a.a, b.a - a.a)) &&
         zero(cross(a.b - a.a, b.b - a.a));
}

double sq(double a) { return a * a; }

double dist(pt p, pt q) {
  return sqrt(sq(p.x - q.x) + sq(p.y - q.y));
}

bool intersect(seg a, seg b) {
  if (collinear(a, b)) {
    cout << "colliner" << endl;
    double maxDist = 0;
    maxDist = max(maxDist, dist(a.a, a.b));
    maxDist = max(maxDist, dist(a.a, b.a));
    maxDist = max(maxDist, dist(a.a, b.b));
    maxDist = max(maxDist, dist(a.b, b.a));
    maxDist = max(maxDist, dist(a.b, b.b));
    maxDist = max(maxDist, dist(b.a, b.b));
    return maxDist < dist(a.a, a.b) + dist(b.a, b.b) + EPS;
  }
  return ccw(a.a, a.b, b.a) != ccw(a.a, a.b, b.b) &&
         ccw(b.a, b.b, a.a) != ccw(b.a, b.b, a.b);
 }



int main() {
  int polysize = 0;
  cin >> polysize;
  pt points[polysize + 1];
  seg segs[polysize + 1];

  for (int i = 0; i < polysize; i ++) {
    pt p;
    cin >> p.x >> p.y;  
    points[i] = p;
  }
  for (int i = 0; i < polysize - 1; i ++) {
    seg s;
    s.a = points[i];
    s.b = points[i + 1];
    segs[i] = s;
  }
  seg s;
  s.a = points[polysize - 1];
  s.b = points[0];
  segs[polysize - 1]  = s;

  for (int i = 0; i < polysize; i ++) {
    ///cout << segs[i].a.x << " " << segs[i].a.y <<" point " <<  segs[i].b.x << " " <<segs[i].b.y << endl;
  }
  int queries;
  cin >> queries;

  for (int i = 0; i < queries; i ++) {
    pt p;
    cin >> p.x >> p.y;
    pt q;
    q.x = magicx;
    q.y = magicy;
    seg line;
    line.a = p;
    line.b = q;

    cout << line.a.x << " " <<line.a.y <<" point " <<  line.b.x << " " <<line.b.y << endl;
    int count = 0;

    for (int j = 0; j < polysize; j ++) {
      seg pline;
      pline.a = p;
      pline.b = p;
      if (intersect(pline, segs[j])) {
        cout << segs[j].a.x << " " <<segs[j].a.y <<" segmented " <<  segs[j].b.x << " " <<segs[j].b.y << endl;
        cout << pline.a.x << " " <<pline.a.y <<" point thingo " <<  pline.b.x << " " <<pline.b.y << endl;
        cout << 1 << endl;
        count = -1;
        break;
      }
      if (intersect(line, segs[j])) {
        count ++;
      }


    }

    if (count == -1) {

    } else if (count % 2 == 0) {
      cout << 0 << endl;
    } else {
      cout << 2 << endl;
    }

  }

  return 0;
}

