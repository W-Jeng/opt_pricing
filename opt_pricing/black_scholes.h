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
	void set_dp();
	void set_dn();

private:
	const double& stock_price;
	const double& strike_price;
	const double& volatility;
	const double& risk_free_rate;
	const double& time_to_exp;
	double dp;
	double dn;
};

#endif 