#include <iostream>
#include <vector>

int get1DVectorIndex(int n, int m, int i, int j, int k)
{
  return n * n * i + m * j + k;
}

void initialize3DVector(std::vector<std::vector<std::vector<int>>> &v, int n, int m, int p)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      for (int k = 0; k < p; k++)
      {
        v[i][j][k] = i + j * k + std::rand() % 100;
      }
    }
  }
}

void copy3DTo1DVector(std::vector<std::vector<std::vector<int>>> &_3D, std::vector<int> &_1D, int n, int m, int p)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      for (int k = 0; k < p; k++)
      {
        _1D.push_back(_3D[i][j][k]);
      }
    }
  }
}

void assertion(std::vector<std::vector<std::vector<int>>> &_3D, std::vector<int> &_1D, int n, int m, int p, int i, int j, int k)
{
  int index = get1DVectorIndex(n, m, i, j, k);
  if (_1D[index] != _3D[i][j][k])
  {
    std::cout << "Assertion failed\n\nExpected: " << _3D[i][j][k] << ", Got: " << _1D[index] << std::endl;
  }
  else
  {
    std::cout << "Assertion passed\n";
  }
}

int main()
{
  std::vector<std::vector<std::vector<int>>> _3DVector(10, std::vector<std::vector<int>>(10, std::vector<int>(10)));
  initialize3DVector(_3DVector, 10, 10, 10);
  std::vector<int> _1DVector;
  copy3DTo1DVector(_3DVector, _1DVector, 10, 10, 10);

  assertion(_3DVector, _1DVector, 10, 10, 10, 0, 0, 0);
  assertion(_3DVector, _1DVector, 10, 10, 10, 0, 0, 1);
  assertion(_3DVector, _1DVector, 10, 10, 10, 0, 1, 0);
  assertion(_3DVector, _1DVector, 10, 10, 10, 0, 1, 1);
  assertion(_3DVector, _1DVector, 10, 10, 10, 1, 0, 0);
  assertion(_3DVector, _1DVector, 10, 10, 10, 1, 0, 1);
  assertion(_3DVector, _1DVector, 10, 10, 10, 1, 1, 0);
  assertion(_3DVector, _1DVector, 10, 10, 10, 1, 1, 1);
  assertion(_3DVector, _1DVector, 10, 10, 10, 5, 6, 7);
  assertion(_3DVector, _1DVector, 10, 10, 10, 4, 5, 8);
  assertion(_3DVector, _1DVector, 10, 10, 10, 9, 9, 9);
  return 0;
}
