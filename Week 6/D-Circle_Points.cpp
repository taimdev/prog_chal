// Taimur Azhar z5116684
// Prog Chal
// Week 6 Problem D - Circles and Points

#include <stdlib.h>
#include <iostream>  
#include <math.h> 
#include <algorithm>  

using namespace std;  
const int Nlim = 333;  
const double epsilon = 1e-8;  

int n, ans;  

struct point {  
    double x,y;   
} point_arr[Nlim];  

bool cmp(point p, point q) {  
    return p.x < q.x || (p.x == q.x && p.y < q.y);  
}  
double dist(point p, point q) {  
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);  
}  


int check_point (point p,point q) {  
    point tmp;
    tmp.x = (p.x + q.x) / 2;
    tmp.y = (p.y + q.y) / 2;  
    double angle = atan2(p.y - q.y, p.x - q.x) + acos( - 1.0) /  2;  
    double len = sqrt(1 - dist(p, q) / 4);  
    tmp.x += cos(angle) * len;  
    tmp.y += sin(angle) * len;  

    int ret = 0;  
    for (int i = 0; i < n; ++ i) {
        if (dist(point_arr[i], tmp) <= 1 + epsilon) {
            ++ ret;  
        }
    }
    return ret;  
} 
int main() {  
    while (cin >> n) {  
        if ( n == 0) return 0;
        for (int i = 0; i < n; ++ i)  
            cin >> point_arr[i].x >> point_arr[i].y;
        sort(point_arr, point_arr + n, cmp);  
        ans = n > 0;  
        for (int i = 0; i < n; ++ i)  
            for (int j = i + 1; j < n && (point_arr[j].x - point_arr[i].x) <= 2; ++ j)  
                if (dist(point_arr[i], point_arr[j]) <= 4)  
                    ans = max(ans, max(check_point(point_arr[i], point_arr[j]), check_point(point_arr[j], point_arr[i])));  
        cout << ans << endl; 
    }  
    return 0;  
} 