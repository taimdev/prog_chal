// Taimur Azhar z5116684
// Prog Chal
// Week 6 Problem B - Build Fences

#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>
#include <cstdio>

#define x first
#define y second

using namespace std;

const double EPS = 1e-8;
typedef pair <double, double> pt;


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

double sq(double a) { return a * a; }

double dist(pt p, pt q) {
  return sqrt(sq(p.x - q.x) + sq(p.y - q.y));
}

vector<pt> half_hull(vector<pt> pts) {
   vector<pt> res;
   for (int i = 0; i < pts.size(); i++) {
      // ccw means we have a left turn; we don't want that
      while (res.size() >= 2 && ccw(pts[i], res[res.size()-1], res[res.size()-2])) {
         res.pop_back();
      }
      res.push_back(pts[i]);
   }
  return res;
}

vector<pt> convex_hull(vector<pt> pts) {
   sort(pts.begin(), pts.end());
   vector<pt> top = half_hull(pts);
   reverse(pts.begin(), pts.end());
   vector<pt> bottom = half_hull(pts);
   top.pop_back();
   bottom.pop_back();
   vector<pt> res(top.begin(), top.end());
   res.insert(res.end(), bottom.begin(), bottom.end());
  return res;
}
int main() {
   int tests;
   cin >> tests;
   while (tests != 0) {
      cin;
      int sheep_num;
      cin >> sheep_num;
      
      vector<pt> pts;
      pts.clear();

      map<pt, int> mapping;
      mapping.clear();

      for (int i = 0; i < sheep_num; ++i) {
         int x_cord, y_cord;
         cin >> x_cord >> y_cord;
         pt point = make_pair(y_cord, x_cord);
         pts.push_back(point);
         mapping.insert(make_pair(point, i + 1));
      }

      vector<pt> ans = convex_hull(pts);
     // cout << "answer for  " << endl;

      if (sheep_num == 1) {
         cout << "0.00" << endl;
         cout << 1 << endl << endl;
         tests --;
         continue;
      }
      double distance = 0;
      vector<pt>::iterator prev = ans.begin();
      for (vector<pt>::iterator it = ans.begin(); it != ans.end(); it ++) {
         //cout << it->x << " dab " << it->y << endl;
         if (prev == it) {

         } else {
            distance += dist(*prev, *it);
            //cout << "current dist" << distance << endl;
            prev = it;
         }
      }
      vector<pt>::iterator it = ans.begin();
      vector<pt>::reverse_iterator rit = ans.rbegin();
      distance += dist(*it, *rit);
      cout << setprecision(2)<< fixed <<  distance << endl;
      ///"%.2f"
      //printf("%.4g\n", distance);
      reverse(ans.begin() + 1, ans.end());
      for (vector<pt>::iterator it = ans.begin(); it != ans.end(); it ++) {
         cout << mapping[*it] << " ";
      }
      tests --;
      //if (tests == 1) {
      //   cout << endl;
      //} else {
         cout << endl << endl;
      //}
   }
   return 0;
}



