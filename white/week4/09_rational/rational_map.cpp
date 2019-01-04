#include <iostream>
#include <map>
#include <set>
#include <vector>
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

bool operator< (const Rational& l, const Rational& r)
{
   return l.Numerator()*r.Denominator() < r.Numerator()*l.Denominator();
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
