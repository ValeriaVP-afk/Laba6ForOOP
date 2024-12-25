#ifndef TEMPLATE_ELECTRICITY_BILL_H
#define TEMPLATE_ELECTRICITY_BILL_H

#include <vector>
#include <iostream>
#include <stdexcept>

// Константы для определения начала года
const int DEFAULT_START_MONTH = 1;

template<typename T>
class TemplateElectricityBill {
public:
    static const int MONTHS = 12;

    TemplateElectricityBill(T tariff, int year, int startMonth = DEFAULT_START_MONTH);
    // Конструктор: Инициализирует объект с тарифом, годом и месяцем, с которого начинается расчет

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
    int getShiftedIndex(int month) const; //Возвращает индекс месяца с учетом начального месяца
    void updatePaymentsAndTotal();
};

// Инстанцирование шаблонов
extern template class TemplateElectricityBill<int>; //Объявление для компилятора, что
extern template class TemplateElectricityBill<double>; //будут использоваться типы int и double

#endif // TEMPLATE_ELECTRICITY_BILL_H
