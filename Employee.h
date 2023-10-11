#pragma once
using namespace std;

class Employee {
public:
	virtual void vfunc() = 0;
protected:
	double vacation_days;
	double vacation_hours_per_work_hour;
	double hours_worked;
	double health_insurance_coverage_percent;
	double hourly_rate;
	const int HEALTH_INSURANCE_BASE_COST = 8000;
	double health_insurance_calculated_cost;
	double weeklySalaryCalc();
	double healthCareContributionCalc();
	double vacationTimeCalc();
};

class Professional :public Employee {
private:
	double salary;
public:
	Professional();
	double getVacationDays();
	double getSalary();
	double getHealthInsuranceCost();
	void vfunc() override {};
};

class Nonprofessional :public Employee {	
public:
	Nonprofessional();
	double getVacationDays();
	double getHourlyRate();
	double getHealthInsuranceCost();
	void vfunc() override {};
};