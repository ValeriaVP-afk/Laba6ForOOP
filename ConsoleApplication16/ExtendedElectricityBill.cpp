#include "ExtendedElectricityBill.h"

ExtendedElectricityBill::ExtendedElectricityBill(double tariff, int year)
    : ElectricityBill(tariff, year) {
    monthlyPenalties = new double[MONTHS] {0}; // ������������� ������� ���� ������
}

ExtendedElectricityBill::~ExtendedElectricityBill() {
    delete[] monthlyPenalties; // ����������
}

void ExtendedElectricityBill::setPenalty(int month, double penalty) {
    validateMonth(month); // �������� ������������ ������ ������
    if (penalty < 0) {
        throw std::invalid_argument("Penalty cannot be negative.");
    }
    monthlyPenalties[month - 1] = penalty; // ��������� �������� ���� ��� ���������� ������
    updatePaymentsAndTotal(); // ���������� �������� �����
}

void ExtendedElectricityBill::updatePaymentsAndTotal() {
    totalAmount = 0; // ��������� �������� �����
    for (int i = 0; i < MONTHS; ++i) {
        monthlyPayments[i] = monthlyReadings[i] * tariff + monthlyPenalties[i]; // ���� ���� � �������
        totalAmount += monthlyPayments[i];
    }
}

double ExtendedElectricityBill::getTotalAmount() const {
    return totalAmount; // ���������� ����� ����� � ������ ����
}

void ExtendedElectricityBill::printMonthlyReport() const { // ��������� ������ ������ ������
    std::cout << "Monthly Report for Year " << getYear() << " with Penalties:\n";
    std::cout << "Month\tConsumption\tPayment\t\tPenalty\n";
    for (int i = 0; i < MONTHS; ++i) {
        std::cout << (i + 1) << "\t"
            << monthlyReadings[i] << "\t\t"
            << monthlyPayments[i] << "\t\t"
            << monthlyPenalties[i] << std::endl;
    }
    std::cout << "\nTotal Amount with Penalties: " << totalAmount << "\n\n";
}
