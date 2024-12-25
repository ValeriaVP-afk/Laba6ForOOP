#ifndef TEMPLATE_ELECTRICITY_BILL_H
#define TEMPLATE_ELECTRICITY_BILL_H

#include <vector>
#include <iostream>
#include <stdexcept>

// ��������� ��� ����������� ������ ����
const int DEFAULT_START_MONTH = 1;

template<typename T>
class TemplateElectricityBill {
public:
    static const int MONTHS = 12;

    TemplateElectricityBill(T tariff, int year, int startMonth = DEFAULT_START_MONTH);
    // �����������: �������������� ������ � �������, ����� � �������, � �������� ���������� ������

    void setReading(int month, T reading);
    T getTariff() const;
    int getYear() const;
    int getStartMonth() const;
    T getTotalAmount() const;
    void printMonthlyReport() const;

private:
    T tariff;
    int year;
    int startMonth;
    std::vector<T> readings;
    std::vector<T> payments;
    T totalAmount;

    void validateMonth(int month) const;
    int getShiftedIndex(int month) const; //���������� ������ ������ � ������ ���������� ������
    void updatePaymentsAndTotal();
};

// ��������������� ��������
extern template class TemplateElectricityBill<int>; //���������� ��� �����������, ���
extern template class TemplateElectricityBill<double>; //����� �������������� ���� int � double

#endif // TEMPLATE_ELECTRICITY_BILL_H
