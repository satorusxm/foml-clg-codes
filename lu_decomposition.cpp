#include <iostream>
#include <vector>

using namespace std;

void apply_row_addition(vector<vector<float>>& mat, int source_row, float c, int target_row)
{
	int n = mat.size();

	for (int i = 0; i < n; i++)
		mat[target_row][i] += c * mat[source_row][i];

	return;
}

void lu_decomposition(vector<vector<float>>& mat, vector<vector<float>>& l, vector<vector<float>>& u)
{
	int n = mat.size();
	float c;

	u = mat;
	l = vector<vector<float>> (n, vector<float> (n, 0));

	for (int i = 0; i < n; i++)
		l[i][i] = 1.0;

	for (int rs = 0; rs < n - 1; rs++)
	{
		for (int rt = rs + 1; rt < n; rt++)
		{
			cout << u[rt][rs] << " " << u[rs][rs] << endl;
			c = -1.0 * u[rt][rs] / u[rs][rs];

			apply_row_addition(u, rs, c, rt);
			l[rt][rs] = c;
		}
	}

	return;
}

void print_matrix_row(vector<vector<float>>& mat, int n, int r)
{
	for (int i = 0; i < n; i++)
		cout << mat[r][i] << " ";

	return;
}

int main()
{
	int n;
	cin >> n;

	vector<vector<float>> mat(n, vector<float> (n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mat[i][j];

	vector<vector<float>> l, u;
	lu_decomposition(mat, l, u);

	for (int i = 0; i < n; i++)
	{
		cout << " | ";
		print_matrix_row(mat, n, i);
		cout << "| ";

		cout << (i == n / 2 ? "=" : " ");

		cout << " | ";
		print_matrix_row(l, n, i);
		cout << "| ";

		cout << " | ";
		print_matrix_row(u, n, i);
		cout << "| ";

		cout << endl;
	}

	return 0;
}

