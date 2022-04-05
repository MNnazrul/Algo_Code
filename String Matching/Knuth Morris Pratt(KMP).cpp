#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

string text, pattern;
int n, m;

vi create_lps() {
   vi lps(pattern.size(), 0);
   int index = 0;
   for (int i = 1; i < m; ) {
      if(pattern[index] == pattern[i]) lps[i] = index + 1, index++, i++;
      else {
         if(index != 0) index = lps[index-1];
         else lps[i] = index, i++;
      }
   }
   return lps;
}

bool match(vi lps) {
   int i = 0, j = 0;
   
   // i -> text, j -> pattern;;;;

   while(i < text.size()) {
      if(text[i] == pattern[j]) {
         i++; j++;
      } else {
         if(j != 0) j = lps[j-2];
         else i++;
      }

      if(j == m) {
         return true;
      }
   }

   return false;
}

int32_t main() {

   cin >> text >> pattern;
   n = text.size(); m = pattern.size();

   vi lps = create_lps();

   if(n >= m && match(lps)) cout << "found" << endl;
   else cout << "Not found" << endl;  
   for (int i : lps) cout << i << ' '; cout << endl;

   return 0;
}