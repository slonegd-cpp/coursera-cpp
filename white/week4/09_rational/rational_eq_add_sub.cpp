#include <iostream>
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
      if (denominator == 0) {
         this->numerator = 0;
         this->denominator = 1;
      } else {
         auto n = nod(std::abs(numerator), std::abs(denominator));
         this->numerator = std::abs(numerator / n);
         this->denominator = std::abs(denominator / n);
         if (numerator < 0 and denominator > 0 or numerator > 0 and denominator < 0) {
            this->numerator *= -1;
         }
         if (numerator == 0)
            this->denominator = 1;
      }
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


int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
