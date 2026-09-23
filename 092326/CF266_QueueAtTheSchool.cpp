#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, t;
    string line;
    cin >> N >> t >> line;

    // iterate t times
    for (int i=0; i<t; i++) {
        // go through the string (except last char)
        for (int j=0; j<N-1; j++) {
            if (line[j] == 'B' && line[j+1] == 'G') {
                // there is a boy before a girl
                line[j+1] = 'B';
                line[j] = 'G';
                j++; // skip over the pair
            }
        }
    }

    cout << line;
}