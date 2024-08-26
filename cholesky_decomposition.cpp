/*
 * Cholesky Decomposition Method is used to decompose a symmetric square matrix into a product of a Lower Triangular Matrix (L) and it's transpose.
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void cholesky_decomposition(vector<vector<float>>& mat, vector<vector<float>>& l)
{
	int n = mat.size();
	float s, t;

	l = vector<vector<float>> (n, vector<float> (n, 0));

	for (int k = 0; k < n; k++)
	{
		s = 0;
		for (int i = 0; i <= k; i++)
		{
			if (k == i)
				l[k][i] = sqrt(mat[k][i] - s);
			else
			{
				t = 0;
				for (int j = 0; j < i; j++)
					t += l[k][j] * l[i][j];

				l[k][i] = (mat[k][i] - t) / l[i][i];
				s += pow(l[k][i], 2);
			}
		}
	}

	return;
}

int main()
{
	int n;
	cin >> n;

	vector<vector<float>> mat(n, vector<float> (n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << "(" << i << ", " << j << "): ";
			cin >> mat[i][j];
			mat[j][i] = mat[i][j];
		}
	}

	vector<vector<float>> l;

	cholesky_decomposition(mat, l);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << l[i][j] << " ";
		cout << endl;
	}

	return 0;
}
