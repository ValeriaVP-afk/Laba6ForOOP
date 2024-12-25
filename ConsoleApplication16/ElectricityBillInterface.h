#ifndef ELECTRICITY_BILL_INTERFACE_H
#define ELECTRICITY_BILL_INTERFACE_H

class ElectricityBillInterface {
public:
    virtual ~ElectricityBillInterface() = default; // Виртуальный деструктор
    virtual void setReading(int month, double reading) = 0; // Установка показаний
    virtual void printMonthlyReport() const = 0; // Вывод отчета
    virtual double getTotalAmount() const = 0; // Получение итоговой суммы
};

#endif