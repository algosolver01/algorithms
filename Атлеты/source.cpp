#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long getMaxMass(vector <long> & massa, vector<long> & strength) {
	sort(massa.begin(), massa.end());
	sort(strength.begin(), strength.end());
	long maxHeight = 1;
	long totalMassa = massa[0];
	for (long i = 1; i < massa.size(); i++) {
		if (strength[i] >= totalMassa) {
			totalMassa += massa[i];
			maxHeight++;
		}
	}
	return maxHeight;
}

int main() {
	long s = 0;
	long m = 0;
	vector <long> massa, strength;
	while (cin >> m  && cin>>s) {
		massa.push_back(m);
		strength.push_back(s);
	}
	long maxHeight=getMaxMass(massa, strength);
	cout << maxHeight << endl;
	return 0;
}