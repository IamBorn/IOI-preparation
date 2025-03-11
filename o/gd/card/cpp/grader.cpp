#include <cassert>
#include <cstdio>
#include <vector>
#include <bits/stdc++.h>
#include "card.h"

using namespace std;

std::vector<int> Shin(int N, std::vector<int> A) {
    sort(A.begin(), A.end());
    vector<int> ans(5, -1);

    int x = A[5];
    for(int i = 0; i < 4; i++){
        int temp = x%5;
        cout << "temp = " << temp << "\n";
        for(int j = 0; j < 5; j++){
            if(ans[j] != -1){
                continue;
            }

            if(temp == 0){
                ans[j] = A[i];
                cout << j << "\n";
                break;
            }
            temp--;
        }
        x/=5;
    }

    for(int i = 0; i < 5; i++){
        if(ans[i] == -1){
            ans[i] = A[4];
            break;
        }
    }
    //for(int i = 0; i < 5; i++) cout << ans[i] << " ";

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

void wrong_answer(int code) {
    printf("Wrong Answer [%d]\n", code);
    exit(0);
}

int main(int argc, char **argv) {
    int N, Q;
    assert(scanf("%d %d", &N, &Q) == 2);
    std::vector<std::vector<int>> B(Q);
    std::vector<int> answer(Q);
    for(int i = 0; i < Q; i++) {
        std::vector<int> A(6);
        for(int j = 0; j < 6; j++) {
            assert(scanf("%d", &A[j]));
            assert(0 <= A[j] && A[j] <= N - 1);
        }
        B[i] = Shin(N, A);
        if((int) B[i].size() != 5) {
            wrong_answer(1);
        }
        for(int j = 0; j < 5; j++) {
            bool found = false;
            for(int k = 0; k < 6; k++) {
                if(B[i][j] == A[k]) {
                    A[k] = -1;
                    found = true;
                    break;
                }
            }
            if(!found) {
                wrong_answer(2);
            }
        }
        for(int j = 0; j < 6; j++) {
            if(A[j] != -1) {
                answer[i] = A[j];
                break;
            }
        }
    }
    for(int i = 0; i < Q; i++) {
        int output = Lena(N, B[i]);
        if(output != answer[i]) {
            wrong_answer(3);
        }
    }
    printf("Accepted.\n");
}