/**
 * @idea_author: Anton Panov, Vladislav Tselikov
 * @code_author: Anton Panov
 * @problem:
 *  * Code count all variants
 * @pcms: Wrong answer, test 2
 * @date: 08.10.2022
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

int main() {
    ll n; cin >> n;
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>> (4, vector<ll> (8)));
    dp[0][0][0b000] = 1;
    dp[0][1][0b010] = 1;
    if (n > 1) {
        dp[0][1][0b001] = 1;
        dp[0][2][0b011] = 1;
    }


    for (ll i = 1; i < n - 1; i++) {
        dp[i][0][0b000] = (dp[i - 1][0][0b000] + dp[i - 1][1][0b100]) % mod;
        dp[i][1][0b100] = (dp[i - 1][1][0b010] + dp[i - 1][2][0b110]) % mod;
        dp[i][1][0b010] = (dp[i - 1][1][0b001] + dp[i - 1][2][0b101]) % mod;
        dp[i][1][0b001] = (dp[i - 1][0][0b000] + dp[i - 1][1][0b100]) % mod;
        dp[i][2][0b011] = (dp[i - 1][1][0b001] + dp[i - 1][2][0b101]) % mod;
        dp[i][2][0b101] = (dp[i - 1][1][0b010] + dp[i - 1][2][0b110]) % mod;
        dp[i][2][0b110] = (dp[i - 1][2][0b011] + dp[i - 1][3][0b111]) % mod;
        dp[i][3][0b111] = (dp[i - 1][2][0b011] + dp[i - 1][3][0b111]) % mod;
    }

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < 4; j++) {
            cout << dp[i][j][0b000] << dp[i][j][0b010] << dp[i][j][0b100] << dp[i][j][0b110];
            cout << endl;
        }
        cout << endl;
    }

    ll res = 0;
    for (ll i = 0; i < 4; i++) {
        res = (res + dp[n - 1][i][0b000] + dp[n - 1][i][0b010] + dp[n - 1][i][0b100] + dp[n - 1][i][0b110]) % mod;
    }

    cout << res;

    return 0;
}