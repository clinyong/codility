/*
 * FrogRiverOne
 * Find the earliest time when a frog can jump to the other side of a river.
 * */

int solution(int X, int A[], int N) {
    int position[X];
    int i, j;
    int last = -1;

    for(i = 0; i < X; i++) {
        position[i] = 0;
    }

    for(i = 0; i < N; i++) {
        j = A[i] - 1;
        if(j < X && position[j] == 0) {
			// Record the time of last coverd position
            last = i;
            position[j] = 1;
        }
    }

    for(i = 0; i < X; i++) {
        if(position[i] == 0) {
            return -1;
        }
    }

    return last;
}
