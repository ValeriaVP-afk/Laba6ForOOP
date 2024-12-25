#ifndef EXTENDED_ELECTRICITY_BILL_H
#define EXTENDED_ELECTRICITY_BILL_H

#include "ElectricityBill.h"

class ExtendedElectricityBill : public ElectricityBill {
public:
    ExtendedElectricityBill(double tariff, int year);
    ~ExtendedElectricityBill();

    void setPenalty(int month, double penalty);
    double getTotalAmount() const override;
    void printMonthlyReport() const override;

private:
    double* monthlyPenalties;
    void updatePaymentsAndTotal() override;
};

#endif
