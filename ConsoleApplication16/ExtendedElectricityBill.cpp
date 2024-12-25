#include "ExtendedElectricityBill.h"

ExtendedElectricityBill::ExtendedElectricityBill(double tariff, int year)
    : ElectricityBill(tariff, year) {
    monthlyPenalties = new double[MONTHS] {0}; // Инициализация массива пени нулями
}

ExtendedElectricityBill::~ExtendedElectricityBill() {
    delete[] monthlyPenalties; // Деструктор
}

void ExtendedElectricityBill::setPenalty(int month, double penalty) {
    validateMonth(month); // Проверка корректности номера месяца
    if (penalty < 0) {
        throw std::invalid_argument("Penalty cannot be negative.");
    }
    monthlyPenalties[month - 1] = penalty; // Установка значения пени для указанного месяца
    updatePaymentsAndTotal(); // Обновление итоговой суммы
}

void ExtendedElectricityBill::updatePaymentsAndTotal() {
    totalAmount = 0; // Обнуление итоговой суммы
    for (int i = 0; i < MONTHS; ++i) {
        monthlyPayments[i] = monthlyReadings[i] * tariff + monthlyPenalties[i]; // Учет пени в платеже
        totalAmount += monthlyPayments[i];
    }
}

double ExtendedElectricityBill::getTotalAmount() const {
    return totalAmount; // Возвращаем общую сумму с учетом пени
}

void ExtendedElectricityBill::printMonthlyReport() const { // Изменения логики вывода отчёта
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
