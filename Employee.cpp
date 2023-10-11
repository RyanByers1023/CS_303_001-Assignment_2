#include "Employee.h"

double Employee::weeklySalaryCalc() {
	return (hours_worked * hourly_rate);
}

double Employee::healthCareContributionCalc() {
	return HEALTH_INSURANCE_BASE_COST - (HEALTH_INSURANCE_BASE_COST * health_insurance_coverage_percent);
}

double Employee::vacationTimeCalc() {
	return (vacation_hours_per_work_hour * hours_worked) * 52; //52 weeks in a year
}

Professional::Professional() {
	vacation_days = 11.0;
	vacation_hours_per_work_hour = 0;
	hours_worked = 40.0;
	health_insurance_coverage_percent = 0.19;
	hourly_rate = 0.0;
	health_insurance_calculated_cost = healthCareContributionCalc();
	salary = 72000.0;
}

double Professional::getVacationDays() {
	return vacation_days;
}

double Professional::getSalary() {
	return salary;
}

double Professional::getHealthInsuranceCost() {
	return health_insurance_calculated_cost;
}

Nonprofessional::Nonprofessional() {
	vacation_hours_per_work_hour = 0.004;
	hours_worked = 30;
	vacation_days = vacationTimeCalc();
	health_insurance_coverage_percent = 0.09;
	hourly_rate = 19.54;
	health_insurance_calculated_cost = healthCareContributionCalc();
}

double Nonprofessional::getVacationDays() {
	return vacation_days;
}

double Nonprofessional::getHourlyRate() {
	return hourly_rate;
}

double Nonprofessional::getHealthInsuranceCost() {
	return health_insurance_calculated_cost;
}


