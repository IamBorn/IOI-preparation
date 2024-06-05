#include "supertrees.h"
#include <vector>

using namespace std;

int construct(vector<vector<int>> p) {
	int n = p.size();
	vector<vector<int>> answer(n, vector<int>(n, 0));

	bool can = true;
	for(int i = 0; i < n && can; i++){
		for(int j = 0; j < n; j++){
			if(p[i][j] != p[j][i])
			can = false;
			break;
		}
	}
	if(!can){
		return 0;
	}
	build(answer);
	return 1;
}
