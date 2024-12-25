#include "ElectricityBill.h"

ElectricityBill::ElectricityBill(double tariff, int year) : year(year), tariff(tariff), totalAmount(0) {
    if (tariff <= 0) {
        throw std::invalid_argument("Tariff cannot be zero or negative.");
    }
    if (year < MIN_YEAR || year > MAX_YEAR) {
        throw std::out_of_range("Year must be between 1900 and 3000.");
    }

    monthlyReadings = new double[MONTHS] {0}; // Инициализация массива показаний
    monthlyPayments = new double[MONTHS] {0}; // Инициализация массива платежей
}

ElectricityBill::~ElectricityBill() {
    delete[] monthlyReadings;
    delete[] monthlyPayments;
}

void ElectricityBill::setReading(int month, double reading) {
    validateMonth(month);
    validateReading(reading);

    if (monthlyReadings[month - 1] > 0) {
        throw std::logic_error("Reading for this month has already been set.");
    }

    if (reading > MAX_BILL) {
        throw std::out_of_range("Bill exceeds reasonable limits for one month.");
    }

    monthlyReadings[month - 1] = reading;
    updatePaymentsAndTotal();
}

double ElectricityBill::getTariff() const {
    return tariff;
}

int ElectricityBill::getYear() const {
    return year;
}

double ElectricityBill::getTotalAmount() const {
    return totalAmount;
}

void ElectricityBill::updatePaymentsAndTotal() {
    totalAmount = 0;
    for (int i = 0; i < MONTHS; ++i) {
        monthlyPayments[i] = monthlyReadings[i] * tariff;
        totalAmount += monthlyPayments[i];
    }
}

double ElectricityBill::getAverageConsumption() const {
    double totalConsumption = 0;
    int count = 0;

    for (int i = 0; i < MONTHS; ++i) {
        totalConsumption += monthlyReadings[i];
        count++;
    }

    if (count == 0) {
        throw std::runtime_error("Cannot calculate average consumption: no readings available.");
    }

    return totalConsumption / count;
}

void ElectricityBill::printMonthlyReport() const {
    std::cout << "Monthly Report for Year " << year << ":\n";
    std::cout << "Month\tConsumption\tPayment\n";
    for (int i = 0; i < MONTHS; ++i) {
        std::cout << (i + 1) << "\t"
            << monthlyReadings[i] << "\t\t"
            << monthlyPayments[i] << std::endl;
    }
    std::cout << "\nTotal Amount: " << totalAmount << "\n\n";
}

void ElectricityBill::validateMonth(int month) const {
    if (month < 1 || month > MONTHS) {
        throw std::out_of_range("Month must be between 1 and 12.");
    }
}

void ElectricityBill::validateReading(double reading) const {
    if (reading < 0) {
        throw std::invalid_argument("Reading cannot be negative.");
    }
}

void ElectricityBill::printMonthInfo(int month) const {
    validateMonth(month);
    std::cout << "Month: " << month << "\n"
        << "Reading: " << monthlyReadings[month - 1] << " kWh\n"
        << "Payment: " << monthlyPayments[month - 1] << "\n";
}

double ElectricityBill::operator[](int month) const {
    validateMonth(month);
    return monthlyPayments[month - 1];
}

std::ostream& operator<<(std::ostream& out, const ElectricityBill& ourObject) {
    out << "\nElectricity Bill for Year " << ourObject.year << ":\n"
        << "Tariff: " << ourObject.tariff << "\n"
        << "Total Amount: " << ourObject.totalAmount << "\n";
    return out;
}

double operator+=(double& sum, const ElectricityBill& ourObject) {
    sum += ourObject.getAverageConsumption();
    return sum;
}
