#include <vector>
#include <algorithm>
#include <iostream>

struct Function_part {
   char operation;
   double value;
   auto apply (double v) const
   {
      return operation == '+' ? v + value : v - value;
   }
   void invert() { operation = (operation == '+' ? '-' : '+'); }
};

class Function {
   std::vector<Function_part> parts;
public:
   auto Apply (double v) const
   {
      for (const auto& p : parts)
         v = p.apply(v);
      return v;
   }
   void Invert()
   {
      for (auto& p : parts)
         p.invert();
      std::reverse (parts.begin(), parts.end());
   }
   void AddPart (char op, double v)
   {
      parts.push_back ({op, v});
   }
};



// struct Image {
//   double quality;
//   double freshness;
//   double rating;
// };

// struct Params {
//   double a;
//   double b;
//   double c;
// };

// Function MakeWeightFunction(const Params& params,
//                             const Image& image) {
//   Function function;
//   function.AddPart('-', image.freshness * params.a + params.b);
//   function.AddPart('+', image.rating * params.c);
//   return function;
// }

// double ComputeImageWeight(const Params& params, const Image& image) {
//   Function function = MakeWeightFunction(params, image);
//   return function.Apply(image.quality);
// }

// double ComputeQualityByWeight(const Params& params,
//                               const Image& image,
//                               double weight) {
//   Function function = MakeWeightFunction(params, image);
//   function.Invert();
//   return function.Apply(weight);
// }

// int main() {
//   Image image = {10, 2, 6};
//   Params params = {4, 2, 6};
//   std::cout << ComputeImageWeight(params, image) << std::endl;
//   std::cout << ComputeQualityByWeight(params, image, 46) << std::endl;
//   return 0;
// }