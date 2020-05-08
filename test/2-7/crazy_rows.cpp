#include <iostream>
#include <vector>
using namespace std;

///
/// \brief lower_triangular
/// \param nxn matrix whose elements are 0 or 1.
/// \return minimum number of swap to let the input matrix as lower triangular.
///
int lower_triangular(const vector<vector<int>> &mat) {
  const int n = mat.size();
  if (static_cast<int>(mat[0].size()) != n)
    throw runtime_error("input matrix must be squre.");
  int num_swap{0};

  // comp colidx_last1
  vector<int> colidx_last1(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (mat[i][j] == 1)
        colidx_last1[i] = j;
    }
  }
  cout << "column idx of last1 = ";
  for (auto &i : colidx_last1)
    cout << i << ' ';

  for (int i = 0; i < n; ++i) {
    // comp rowto_i
    int rowto_i = -1;
    for (int j = i; j < n; ++j) {
      if (colidx_last1[j] <= i) {
        rowto_i = j;
        break;
      }
    }

    // swap
    for (int j = rowto_i; j > i; --j) {
      swap(colidx_last1[j], colidx_last1[j - 1]);
      ++num_swap;
    }
  }

  return num_swap;
}

///
/// \brief main
/// \return
///
int main() try {
  //      vector<vector<int>> mat{{1, 0}, {1, 1}};
  //    vector<vector<int>> mat{{0, 0, 1}, {1, 0, 0}, {0, 1, 0}};
  vector<vector<int>> mat{
      {1, 1, 1, 0}, {1, 1, 0, 0}, {1, 1, 0, 0}, {1, 0, 0, 0}};

  cout << "number of minimum swap = " << lower_triangular(mat) << endl;

  return 0;
} catch (runtime_error &e) {
  cerr << e.what() << endl;
} catch (...) {
  cerr << "unkown error occurred.\n";
}
