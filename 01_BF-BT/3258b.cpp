#include <iostream>
#include <vector>
using namespace std;
// success 코드

int N, Z, M;

int main() {
    //freopen("input.txt", "r", stdin);
    cin >> N >> Z >> M; // 필드, 도착지, 장애물 수
    vector<int> block(M);
    for (int i = 0; i < M; i++) {
        cin >> block[i];
    }

    if (M == 0) {
        cout << 1 << endl;
        return 0;
    }

    for (int k = 1; k < N; k++) { // 작은 k부터 시도
        int pos = 0; // 시작 위치는 0 (1로 하면 장애물과 맞지 않음)
        bool valid = true;

        while (true) {
            pos = (pos + k) % N;

            // 장애물 검사
            for (int j = 0; j < M; j++) {
                if (pos == block[j] - 1) { // 장애물 위치는 1부터 시작하므로 -1
                    valid = false;
                    break;
                }
            }

            if (!valid || pos == 0) { // 장애물에 도달하거나 시작 위치로 돌아오면 중단
                break;
            }

            if (pos == Z - 1) { // 목표 지점에 도달하면 성공
                cout << k << endl;
                return 0;
            }
        }
    }

    return 0;
}
