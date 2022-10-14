#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    stops.push_back(dist);
    int lastStop = 0;
    int numRefills = 0;

    for(int i = 0; i < stops.size(); i++){

        if(stops[i] - lastStop <= tank){

            int x = stops[i];

            if(stops[i+1] - lastStop > tank && i+1 < stops.size()){
                numRefills++;
                lastStop = x;
            }

        }
        else{
            return -1;
        }
    }
    return numRefills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
