#ifndef ELECTRICITY_BILL_H
#define ELECTRICITY_BILL_H

#include "ElectricityBillInterface.h"
#include <iostream>
#include <stdexcept>

class ElectricityBill : public ElectricityBillInterface { // Наследуем интерфейс
public:
    static const int MONTHS = 12;
    static const int MAX_BILL = 10980;
    static const int MIN_YEAR = 1900;
    static const int MAX_YEAR = 3000;

    ElectricityBill(double tariff, int year);
    virtual ~ElectricityBill();

    void setReading(int month, double reading) override; // Реализация из интерфейса
    double getTariff() const;
    int getYear() const;
    double getTotalAmount() const override; // Реализация из интерфейса
    double getAverageConsumption() const;
    virtual void printMonthlyReport() const override; // Реализация из интерфейса

    void printMonthInfo(int month = 1) const;
    double operator[](int month) const;
    friend std::ostream& operator<<(std::ostream& out, const ElectricityBill& ourObject);

protected:
    double* monthlyReadings;
    double* monthlyPayments;
    int year;
    double tariff;
    double totalAmount;

    virtual void updatePaymentsAndTotal();
    void validateMonth(int month) const;
    void validateReading(double reading) const;
};

double operator+=(double& sum, const ElectricityBill& ourObject);

#endif
