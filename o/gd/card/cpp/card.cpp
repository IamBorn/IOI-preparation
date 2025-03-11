#include <vector>
#include <bits/stdc++.h>
#include "card.h"

using namespace std;

namespace SHIN{
    int variable_example = 0;
}

namespace LENA{
    int variable_example = 0;
}

std::vector<int> Shin(int N, std::vector<int> A) {
    sort(A.begin(), A.end());
    vector<int> ans(5, -1);

    int x = A[5];
    for(int i = 0; i < 4; i++){
        int temp = x%5;
        for(int j = 0; j < 5; j++){
            if(A[j] == -1){
                continue;
            }

            if(temp == 0){
                ans[j] = A[i];
            }
            temp--;
        }
    }

    for(int i = 0; i < 5; i++){
        if(ans[i] == -1){
            ans[i] = A[4];
        }
    }
    for(int i = 0; i < 5; i++) cout << ans[i] << " ";

    return ans;
}

int Lena(int N, std::vector<int> B) {
    auto A = B;
    sort(A.begin(), A.end());
    int ans = 0;
    int cnt = 1;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            if(B[j] > A[i]) ans += cnt;
            else if(B[j] == A[i]) break;
        }
        cnt*=5;
    }
    return ans;
}
