#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <algorithm>

using namespace std;

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix


class Matrix {
   using Row = std::vector<int>;
   std::vector<Row> m;
   int cols_n {0};
public:
   Matrix() = default;
   Matrix (int rows, int cols) { Reset (rows, cols); }
   void Reset (int rows, int cols)
   {
      if (rows < 0 or cols < 0) throw out_of_range("");
      m.resize(rows);
      for (auto& col : m) {
         col.resize(cols);
         std::fill(col.begin(), col.end(), 0);
      }
      cols_n = cols;
   }
   int  At(int row, int col) const { check(row,col); return m.at(row).at(col); }
   int& At(int row, int col)       { check(row,col); return m[row][col]; }
   void check (int row, int col) const
   {
      if (row >= GetNumRows() or row < 0)    throw out_of_range("");
      if (col >= GetNumColumns() or col < 0) throw out_of_range("");
   }

   int GetNumRows() const    { return m.size(); }
   int GetNumColumns() const { return cols_n; }
   // {
   //    if (m.empty())
   //       return 0;
   //    return m.at(0).size();
   // }



   friend bool operator== (const Matrix& l, const Matrix& r);
   friend ostream& operator<< (ostream& s, const Matrix& m);
   friend istream& operator>> (istream& s, Matrix& m);
   friend Matrix operator+ (const Matrix& l, const Matrix& r)
   {
      auto rows = r.GetNumRows();
      auto cols = r.GetNumColumns();
      if (l.GetNumRows() != rows or l.GetNumColumns() != cols) throw invalid_argument("");
      Matrix m (rows, cols);
      for (int r_ = 0; r_ < rows; ++r_)
         for (int c = 0; c < cols; ++c)
            m.At(r_,c) = l.At(r_,c) + r.At(r_,c);
      return m;
   }

};

ostream& operator<< (ostream& s, const Matrix& m)
{
   s << m.GetNumRows() << ' ' << m.GetNumColumns() << endl;
   for (const auto& row : m.m) {
      for (auto i : row)
         s << i << ' ';
      s << endl;
   }
   return s;
}

istream& operator>> (istream& s, Matrix& m)
{
   int rows, cols;
   s >> rows >> cols;
   m.Reset(rows, cols);
   for (auto& row : m.m) {
      for (auto& i : row)
         s >> i;
   }
   return s;
}

bool operator== (const Matrix& l, const Matrix& r) { return l.m == r.m and l.cols_n == r.cols_n; }



int main() {
   Matrix one;
   Matrix two;

   cin >> one >> two;
   cout << one + two << endl;
   return 0;
}
