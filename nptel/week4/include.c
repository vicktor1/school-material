// Let us consider the Hadamard product operation for 2 matrices of floating point
// numbers.
// 
// Given input matrices A and B, both of size m x n, the Hadamard product is an
// elementwise product operation yielding an output matrix C such that every
// element C[i][j] = A[)*BEIE]
// 
// Implement a CUDA program which takes as input i) the number of test cases ii)
// values of m and n depicting the dimensions of the input matrices A and B iii) the
// 
// matrix elements of A iv) the matrix elements of B, performs the Hadamard product
// operation and prints the resultant matrix C.
// 
// 
// Input:
// 2
// 22 Matrix size for the first test case
// 1.02.0 = =
// 3.04.0 } Data for first matrix row wise per line
// 1.02.0 = =
// 3040 Data for second matrix row wise per line
// 44 a on
// 1,0 2.0 3.04.0 ——_| Matrix size for the second test case
// Lose soay Pm LDat for frst matrix row wise per line
// 1.0 2.0 3.0 4.0
// 1.0 2.0 3.0 4.0
// 1.0 2.0 3.04.0 Data for second matrix row wise per line
// 1.0 2.0 3.0 4.0
// 1.0 2.0 3.0 4.0
// 
// Output
// 
// 1.04.0 } Output of the first test case
// 
// 9.0 16.0
// 
// 1.0 4.0 9.0 16.0
// 
// 
// 
// 
// 
// 1.0 4.0 9.0 16.0 <+———— Output of the second test case
// 1.0 4.0 9.0 16.0
// 1.0 4.0 9.0 16.0
// 
// 
// 
// 
// 
// The first line contains the number of input test cases. For each input test case, the first
// line denotes the values of m and n. Following this, the next m*n values represent the
// floating point values of input matrix A. After this, the next nn values represent the
// floating point values of input matrix B. The output to each input test case is the
// resultant matrix C which is to be printed in a particular format. Each output matrix
// will have m lines of n space separated floating point values. For two successive input
// test cases, there should be no newline between the resulting output matrices during
// printing.
// 
// The program will be evaluated using automated code checker. The generated
// output file must be in the exact format as stated above. So any extra spaces,
// newline or text/characters will lead to failure of test case evaluation and reduced
// marks.
// 

#include <stdio.h>
#include <stdlib.h>


__global__ void vector_mul(float* out, float *a, float *b, int n) {
	int index = 0;
	int stride = 1;

	for (int i = index; i < n; i += stride) 
		out[i] = a[i] * b[i];
}


int main(int argc, char* argv[])
{
	int m, n, total_testcase;
	float *mat1, *mat2;

	scanf("%d" total_testcase);
	fflush(stdin);

	while (total_testcase--)
	{
		scanf("%d %d", &m, &n);

		// allocate memory for mat1
		mat1 = malloc(sizeof(float) * m * n);
		assert(mat1 != NULL);

		for (int idy = 0; idy < m; idy++)
		{
			for (int idx = 0; idx < n; idx++)
			{
				scanf("%f", &mat1[idy * n + idx]);
			}
		}


		// allocate memory for mat2 
		mat2 = malloc(sizeof(float) * m * n);
		assert(mat2 != NULL);

		for (int idy = 0; idy < m; idy++)
		{
			for (int idx = 0; idx < n; idx++)
			{
				scanf("%f", &mat1[idy * n + idx]);
			}
		}

		free(mat1);
		free(mat2);
	}
	return 0;
}

