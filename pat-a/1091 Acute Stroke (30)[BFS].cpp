#include <cstdio>
#include <deque>
#include <cstring>
#include <vector>
using namespace std;

typedef struct Pi{
    int X, Y, Z;
} Pixel;

int M, N, L, T, p, volume;
int pixels[1300][130][62];
bool visited[1300][130][62];

int X[] = {1, -1, 0, 0, 0, 0};
int Y[] = {0, 0, 1, -1, 0, 0};
int Z[] = {0, 0, 0, 0, 1, -1};

int ValidPixel(Pixel p) {
    if (p.X < 0 || p.Y < 0 || p.Z < 0 || p.X >= M || p.Y >= N || p.Z >= L) return 0;
    if (pixels[p.X][p.Y][p.Z] == 0 || visited[p.X][p.Y][p.Z]) return 0;
    return 1;
}

int BFS(int x, int y, int z) {
    deque<Pixel> Q;
    visited[x][y][z] = true;
    Pixel p;
    p.X = x; p.Y = y; p.Z = z;
    Q.push_back(p);
    int volume = 0;

    while (!Q.empty()) {
        p = Q.front();
        Q.pop_front();
        volume++;
        for (int i = 0; i < 6; i++) {
            int nx = p.X + X[i];
            int ny = p.Y + Y[i];
            int nz = p.Z + Z[i];
            Pixel tmp;
            tmp.X = nx; tmp.Y = ny; tmp.Z = nz;
            if (ValidPixel(tmp)) {
                Q.push_back(tmp);
                visited[nx][ny][nz] = true;
            }
        }
    }

    if (volume < T) volume = 0;

    return volume;
}

int main() {
    scanf("%d %d %d %d", &M, &N, &L, &T);
    for (int k = 0; k < L; k++) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &pixels[i][j][k]);
            }
        }
    }

    volume = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < L; k++) {
                if (!visited[i][j][k] && pixels[i][j][k]) {
                    volume += BFS(i, j, k);
                }
            }
        }
    }

    printf("%d", volume);

    return 0;
}
