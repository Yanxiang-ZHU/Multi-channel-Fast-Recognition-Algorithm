#include <stdio.h>
#include <math.h>

int get_parameter(int* n, int* height) {
	scanf("%d", n);
	if (getchar() == '\n');

	for (int index = 0; index < *n; index++) {
		for (int index_y = 0; index_y < *n; index_y++) {
			scanf("%d", (height+index*(*n)+index_y));
		}
		if (getchar() == '\n');
	}

	return 1;
}

int solve_maxheight(int* height, int* n) {
	int max = 0;
	for (int i = 0; i < (*n) * (*n); i++) {
		if (*(height + i) > max) {
			max = *(height + i);
		}
	}
	return max;
}

int floor_bk(int* height, int* n) {
	int num;
	for (int i = 0; i < (*n) * (*n); i++) {
		if (*(height + i)) {
			num++;
		}
	}
	return num;
}

int md_bk(int* height, int n, int h) {
	// take the picture
	int* picture;
	for (int i = 0; i < (n) * (n); i++) {
		if (*(height + i) >= h) {
			*(picture + i) = 1;
		}
	}
	int num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == 0 || picture[i][j - 1] == 0) {
				num++;
			}
			if (j == n || picture[i][j + 1] == 0) {
				num++;
			}
			if (i == 0 || picture[i-1][j] == 0) {
				num++;
			}
			if (i == n || picture[i + 1][j] == 0) {
				num++;
			}
		}
	}

	return num;
}

int main() {
	int n;
	int *height = 0;
	int maxheight;

	get_parameter(&n, height);
	maxheight = solve_maxheight(height, &n);

	int sfc = 0;

	for (int h = 1; h < maxheight; h++) {
		if (h == 1) {
			sfc += 2*floor_bk(height, &n);
		}
		else {
			sfc += md_bk(height, n, h);
		}
	}

	printf("%d", sfc);

	return 0;
}