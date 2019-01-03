constexpr bool Factorial(int i)
{
   int res = 1;
   if (i > 0)
      do { res *= i } while (--i);

   return res;
}

// static_assert (Factorial(1) == 1);
// static_assert (Factorial(-1) == 1);
// static_assert (Factorial(2) == 2);
// static_assert (Factorial(3) == 6);

