/**
 * @idea_author: Anton Panov
 * @code_author: Anton Panov
 * @pcms: Accepted
 * @date: 08.10.2022
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll getMinimal(ll n, ll maxCount, ll i, vector<ll>& prefix) {
    ll l = 0;
    ll r = n;
    while (l + 1 < r) {
        ll m = (l + r) / 2;
        if (!(i - m < 0 && i + m >= n) && prefix[min(i + m, n - 1)] - (i - m > 0 ? prefix[i - m - 1] : 0LL) <= maxCount) {
            l = m;
        } else {
            r = m;
        }
    }

    return l;
}

int main() {
    ll n, r;
    cin >> n >> r;
    vector<ll> sights(n);
    for (ll i = 0; i < n; i++) {
        cin >> sights[i];
    }

    vector<ll> prefix(n);

    for (ll i = 0; i < n; i++) {
        ll ri = n - 1 - i;
        prefix[i] = (i > 0 ? prefix[i - 1] : 0) + sights[i];
    }

    vector<ll> res(n);
    for (ll i = 0; i < n; i++) {
        ll radius = getMinimal(n, r, i, prefix);
        if (radius == 0 && sights[i] > r) {
            res[i] = -1;
        } else {
            res[i] = radius;
        }
    }

    for (ll i = 0; i < n; i++) {
        cout << res[i] << "\n";
    }
    return 0;
}