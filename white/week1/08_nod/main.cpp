#include <iostream>
#include <algorithm>
/*
Пока A > 0 и B > 0:
Если A > B:
A = A % B
иначе:
B = B % A
Вывести A + B
*/
int main()
{
   int a, b;
   std::cin >> a >> b;
   while (a and b) {
      if (a > b)
         a %= b;
      else
         b %= a;
   }
   std::cout << a + b << std::endl;
}