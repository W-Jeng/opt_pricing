#include<iostream>
#include<cmath>
#include "black_scholes.h"
#include "normal_cdf.h"

BlackScholesOptionPricing::BlackScholesOptionPricing(const double& stock_price, const double& strike_price, const double& volatility,
	const double& risk_free_rate, const double& time_to_exp) : stock_price(stock_price), strike_price(strike_price), volatility(volatility),
	risk_free_rate(risk_free_rate), time_to_exp(time_to_exp) {}

double BlackScholesOptionPricing::price(const OptionType& option_type) {
	
	const double dp = set_dp();
	const double dn = set_dn(dp);

	double call_price = stock_price * normal_cdf(dp) - strike_price * std::exp(-risk_free_rate * time_to_exp) * normal_cdf(dn);
	if (option_type == CALL) {
		return call_price;
	} else {
		return call_price + strike_price * std::exp(-risk_free_rate * time_to_exp) - stock_price;
	}
}

double BlackScholesOptionPricing::set_dp() {
	return (log(stock_price / strike_price) + (risk_free_rate + pow(volatility, 2) / 2) * time_to_exp) / (volatility * pow(time_to_exp, 0.5));
}

double BlackScholesOptionPricing::set_dn(const double& dp) {
	return  dp - volatility * pow(time_to_exp, 0.5);
}
