// Taimur Azhar z5116684 Final Exam
// Problem C - 

#include <stdlib.h>
#include <iostream>
#include <set>
#include <map>

#define MOD 1000000007
#define MAX 1000007
#define N 10000007


using namespace std;
typedef long long ll;

ll f[N];
ll freq[MAX];

ll modpow(ll x, ll k) {
   if (k == 0) return 1;

   ll a = modpow(x, k/2) % MOD ;
   a = (a*a) % MOD;
   if (k%2 == 1) a = (a*x) % MOD;
   return a;
}

ll inv(ll x) {
  // By Fermat's little theorem, a^(p-2) is the inverse of a mod p
  return modpow(x, MOD-2);
}

int main() {
   ll input;
   cin >> input;
   if (input == 0) {
      cout << 0 << endl;
   }
   for (ll i = 0; i < input; i ++) {
      ll num;
      cin >> num;
      freq[num] ++;
   }

   f[0] = 1;
   for (ll i = 1; i <= N; i++) {
      f[i] = (i * f[i-1]) % MOD;
   } 
   // Upper Part
   ll res = f[input] % MOD;

   for (int i = 1; i < MAX; i ++) {
      if (freq[i] > 1) {
         res = (res * inv(f[freq[i]])) % MOD;
      }
   }
   
   cout << res << endl;
   return 0;
}