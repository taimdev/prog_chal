// Taimur Azhar z5116684 Final Exam
// Problem B - 

#include <stdlib.h>
#include <iostream>
#include <map>

#define MAX 50007

using namespace std;
typedef long long ll;

int main() {
	int queries;
	cin >> queries;

   int crateno = 1;
   ll warr[MAX];
   ll harr[MAX];
   map<ll, int> wmapp;
   map<ll, int> hmapp;
   for (int i = 0; i < queries; i ++) {
      char type;
      cin >> type;
      if (type == 'D') {
         ll w, h;
         cin >> w >> h;
         warr[crateno] = w;
         harr[crateno] = h;
         wmapp[w] = crateno;
         hmapp[h] = crateno;
         crateno ++;
      } else {
         int targ;
         cin >> targ;
         // do stuff
         ll smolw = warr[targ];
         ll smolh = harr[targ];
         int trig = 0;
         int maxh = 0;
         map<ll, int> recc;
         recc.clear();
         cout << "looing to fit " << smolh << " h and w " << smolw << endl;
         for (map<ll, int>::iterator it = hmapp.begin(); it != hmapp.end(); it ++) {
           cout << "at index " << it->second <<" height " << it->first << endl;
            if ((smolh == it->first) && (smolw == warr[it->second])) {
               cout << "coutninuing" << endl;
               continue;
            }
            if ((smolh <= it->first) && (trig == 0)) {
               cout << "HITTT" << endl;
               maxh = it->first;
               //wmapp.erase(it);
               trig = 1;
               recc[warr[it->second]] = it->second;
               //cout << "adding " << it->second << endl;
            } else if ((maxh == it->first) && (trig == 1)) {
               cout << "collionsion hitt" << endl;
               recc[warr[it->second]] = it->second;
            } else {
               //break;
            }
         }

         if (trig == 0) {
            cout << "RIP" << endl;
         } else {
            map<ll, int>::iterator it = recc.begin();
            cout << it->second << endl;
         }
      }
   }


   return 0;
}