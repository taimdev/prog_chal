// Taimur Azhar z5116684
// Prog Chal
// Week 6 Problem E - Candy's Candy

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define LIM 100100
#define ll long long
using namespace std;

ll n, a[LIM], gcdiv, ans, minval;
vector<ll> factors;

/*
 * gcd
 */

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

void dabb() {
    gcdiv = 0;
    for (int i = 0; i < n; i ++)  {
        cin >> a[i];
        gcdiv = gcd(gcdiv, a[i]);
    }
    factors.clear();
    for (int i = 1; i * i <= gcdiv; i ++) {
        if (gcdiv % i == 0) {
            factors.push_back(i);
            if (i * i != gcdiv)    {
                factors.push_back(gcdiv / i);
            }
        }
    }
    sort(factors.begin(), factors.end());
    ans = 0;
    for (vector<ll>::iterator it = factors.begin(); it != factors.end(); it ++) {
        bool trigger = true;
        ll rem = (a[0] / *it) % n;
        minval = (a[0] / *it - 1) / n;
        for (int i=1; i < n; i++)    {
            if ((a[i] / *it) <= n or ((a[i] / *it) % n) != rem)  {
                trigger = false;
            }
            minval = min(minval, (a[i] / *it - 1) / n);
        }
        if (trigger)  {
            ans += minval;
        }
    }
    cout << ans << "\n";
}

int main() {

    while(cin >> n) {
        if(n == 0) {
            return 0;
        }
        dabb();
    }
}