#include <iostream>
#include "black_scholes.h"

int main()
{   
    std::cout << "Hello World!\n";
    print_smth(42);

    OptionType opt_type = PUT;
    BlackScholesOptionPricing bs_opt(100, 120, 0.1, 0.01, 1);
    
    double option_val = bs_opt.price(opt_type);
    std::cout << "option value: " << option_val << "\n";

    return 0;
}
