#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i=0; i<N; i++) {
        int in;
        cin >> in;
        
        if (in == 1) {
            cout << "HARD";
            return 0; // end program early
        }
    }

    // if didn't end early, no 1s were found
    cout << "EASY";
}