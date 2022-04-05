#include <bits/stdc++.h>

using namespace std;

#define int long long
#define N 10005

string text, pattern;

int n, m, power[2][N], Hash[2][N], patt_hash1, patt_hash2;
int base[] = {1231ll, 1567ll};
int mod[] = {1000000007, 1000000009};

void init() {
   power[0][0] = power[1][0] = 1ll;
   for (int i = 1; i < N; i++) {
      power[0][i] = (power[0][i-1] * base[0]) % mod[0];
      power[1][i] = (power[1][i-1] * base[1]) % mod[1];
   }
}

void hashing() {
   Hash[0][0] = Hash[1][0] = 0ll;
   for (int i = 0; i < n; i++) {
      Hash[0][i+1] = (Hash[0][i] * base[0] % mod[0] + (text[i] - 'a' + 1)) % mod[0];
      Hash[1][i+1] = (Hash[1][i] * base[1] % mod[1] + (text[i] - 'a' + 1)) % mod[1];
   }
   patt_hash1 = 0ll;
   patt_hash2 = 0ll;
   for (int i = 0; i < m; i++) {
      patt_hash1 = (patt_hash1 * base[0] % mod[0] + (pattern[i] - 'a' + 1)) % mod[0];
      patt_hash2 = (patt_hash2 * base[1] % mod[1] + (pattern[i] - 'a' + 1)) % mod[1];
   }
}

int hash_val(int left, int right, int f) {
   return ((Hash[f][right]  - Hash[f][left-1]* power[f][right-left+1] % mod[f])%mod[f] + mod[f]) % mod[f];
}


bool isMatch(int left, int right) {
   return (patt_hash1 == hash_val(left, right, 0) && patt_hash2 == hash_val(left, right, 1));
}


int32_t main () {
   init();

   cin >> text >> pattern;
   n = text.size();
   m = pattern.size();

   hashing();

   for (int i = m; i <= n; i++) {
      if(isMatch(i-m+1, i)) {
         cout << "found pattern" << endl;
      }
   }


   return 0;
}
