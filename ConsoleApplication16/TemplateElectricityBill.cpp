#include "TemplateElectricityBill.h"

// �����������
template<typename T>
TemplateElectricityBill<T>::TemplateElectricityBill(T tariff, int year, int startMonth)
    : tariff(tariff), year(year), startMonth(startMonth), totalAmount(0) {
    if (tariff <= 0) {
        throw std::invalid_argument("Tariff cannot be zero or negative.");
    }
    if (startMonth < 1 || startMonth > MONTHS) {
        throw std::out_of_range("Start month must be between 1 and 12.");
    }
    readings.resize(MONTHS, 0);
    payments.resize(MONTHS, 0);
}

// ��������� ���������
template<typename T>
void TemplateElectricityBill<T>::setReading(int month, T reading) {
    validateMonth(month);
    int index = getShiftedIndex(month);

    if (readings[index] > 0) {
        throw std::logic_error("Reading for this month has already been set.");
    }
    if (reading < 0) {
        throw std::invalid_argument("Reading cannot be negative.");
    }
    readings[index] = reading;
    updatePaymentsAndTotal();
}

// ��������� ������
template<typename T>
T TemplateElectricityBill<T>::getTariff() const {
    return tariff;
}

// ��������� ����
template<typename T>
int TemplateElectricityBill<T>::getYear() const {
    return year;
}

// ��������� ���������� ������
template<typename T>
int TemplateElectricityBill<T>::getStartMonth() const {
    return startMonth;
}

// ��������� �������� �����
template<typename T>
T TemplateElectricityBill<T>::getTotalAmount() const {
    return totalAmount;
}

// ����� ��������� ������
template<typename T>
void TemplateElectricityBill<T>::printMonthlyReport() const {
    std::cout << "Monthly Report for Year " << year << " starting from Month " << startMonth << ":\n";
    std::cout << "Month\tConsumption\tPayment\n";
    for (int i = 0; i < MONTHS; ++i) {
        int logicalMonth = (startMonth + i - 1) % MONTHS + 1;
        std::cout << logicalMonth << "\t" << readings[i] << "\t\t" << payments[i] << std::endl;
    }
    std::cout << "\nTotal Amount: " << totalAmount << "\n\n";
}

// �������� ������������ ������
template<typename T>
void TemplateElectricityBill<T>::validateMonth(int month) const {
    if (month < 1 || month > MONTHS) {
        throw std::out_of_range("Month must be between 1 and 12.");
    }
}

// ��������� ������� � ������ ���������� ������
template<typename T>
int TemplateElectricityBill<T>::getShiftedIndex(int month) const {
    return (month - startMonth + MONTHS) % MONTHS;
}

// ���������� �������� � ����� �����
template<typename T>
void TemplateElectricityBill<T>::updatePaymentsAndTotal() {
    totalAmount = 0;
    for (int i = 0; i < MONTHS; ++i) {
        payments[i] = readings[i] * tariff;
        totalAmount += payments[i];
    }
}

// ��������������� ��������
template class TemplateElectricityBill<int>;
template class TemplateElectricityBill<double>;
