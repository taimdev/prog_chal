// Taimur Azhar z5116684
// Prog Chal
// Week 6 Problem A - Malfatti Circles

#include <stdlib.h>
#include <iostream>  
#include <cmath> 
#include <iomanip>

using namespace std;  

struct Point{  
    double x,y;  
}p1,p2,p3,ic; 

double dist(Point p1,Point p2) {  
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));  
}  

int main() {    
    while(cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y) {
        if ((p1.x == 0) && (p1.y == 0) && (p2.x == 0) && (p2.y == 0) && (p3.x == 0) && (p3.y == 0)) break;
        
        // Distance of each line in the triangle
        double a = dist(p2, p3);  
        double b = dist(p1, p3);  
        double c = dist(p1, p2);  
        // Semiperimeter
        double s = (a + b + c) / 2;  
        // Incentre of the triangle
        ic.x = (a * p1.x + b * p2.x + c * p3.x) / (a + b + c);  
        ic.y = (a * p1.y + b * p2.y + c * p3.y) / (a + b + c);
        // Inneradius
        double ir = sqrt(s * (s - a) * (s - b) * (s - c)) / s; 
        // The three distances from the incentre
        double d = dist(p1, ic);  
        double e = dist(p2, ic);  
        double f = dist(p3, ic);  
        // Each radii
        double r1 = ir / (2 * (s - a)) * (s + d - ir - e - f);  
        double r2 = ir / (2 * (s - b)) * (s + e - ir - d - f);  
        double r3 = ir / (2 * (s - c)) * (s + f - ir - d - e);  

        cout << setprecision(9) << r1 << " " << r2 << " " << r3 << " " << endl;
    }
    return 0;  
}  