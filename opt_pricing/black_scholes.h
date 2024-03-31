#pragma once
#ifndef BLACK_SCHOLES_H
#define BLACK_SCHOLES_H

enum OptionType {
	CALL,
	PUT
};

double normal_cdf(double x);

class BlackScholesOptionPricing {
public:
	BlackScholesOptionPricing(const double& stock_price, const double& strike_price, const double& volatility,
		const double& risk_free_rate, const double& time_to_exp);

	double price(const OptionType& option_type);
	double set_dp();
	double set_dn(const double& dp);

private:
	const double& stock_price;
	const double& strike_price;
	const double& volatility;
	const double& risk_free_rate;
	const double& time_to_exp;
	
};

#endif 