#include <iostream>
using namespace std;

int x,y;

int main() {
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    cin >> x >> y;

    int ans = 0;
    int pos = x;
    int delta = 1;
    while (true) {
        int before = pos;
        int after = x + delta;

        // cout << before << "->" << after << "\n";

        if (y >= min(before, after) && y <= max(before, after)) {
            // between before and after
            int dist = abs(before-y);
            // cout << "found after this len travelled " << dist << "\n";
            ans += dist;
            break;
        }

        int dist = abs(before-after);

        pos = after;
        ans += dist;

        delta *= -2;
    }

    cout << ans;
}