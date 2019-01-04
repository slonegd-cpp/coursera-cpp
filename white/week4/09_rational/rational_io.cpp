#include <iostream>
#include <sstream>
using namespace std;

int nod (int a, int b)
{
   while (a and b) {
      if (a > b)
         a %= b;
      else
         b %= a;
   }
   return a + b;
}

class Rational {
public:
   Rational() : numerator(0), denominator(1) {}

   Rational (int numerator, int denominator) {
      auto n = nod(std::abs(numerator), std::abs(denominator));
      this->numerator = std::abs(numerator / n);
      this->denominator = std::abs(denominator / n);
      if (numerator * denominator < 0) {
         this->numerator *= -1;
      }
      if (numerator == 0)
         this->denominator = 1;
   }

   int Numerator() const { return numerator; }

   int Denominator() const { return denominator; }

private:
   int numerator;
   int denominator;
};

bool operator== (const Rational& l, const Rational& r)
{
   return l.Denominator() == r.Denominator() and l.Numerator() == r.Numerator();
}

Rational operator+ (const Rational& l, const Rational& r)
{
   return Rational {
        l.Numerator()*r.Denominator() + l.Denominator()*r.Numerator()
      , l.Denominator()*r.Denominator()
   };
}

Rational operator- (const Rational& l, const Rational& r)
{
   return Rational {
        l.Numerator()*r.Denominator() - l.Denominator()*r.Numerator()
      , l.Denominator()*r.Denominator()
   };
}

Rational operator* (const Rational& l, const Rational& r)
{
   return Rational {
        l.Numerator()*r.Numerator()
      , l.Denominator()*r.Denominator()
   };
}

Rational operator/ (const Rational& l, const Rational& r)
{
   return Rational {
        l.Numerator()*r.Denominator()
      , l.Denominator()*r.Numerator()
   };
}

ostream& operator<< (ostream& s, const Rational& r)
{
   s << r.Numerator() << '/' << r.Denominator();
   return s;
}

istream& operator>> (istream& s, Rational& r)
{
   int n,d;
   if (not (s >> n)) return s;
   s.ignore(1);
   if (not (s >> d)) return s;
   r = Rational {n,d};
   return s;
}


int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
