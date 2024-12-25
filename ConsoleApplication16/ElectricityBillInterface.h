#ifndef ELECTRICITY_BILL_INTERFACE_H
#define ELECTRICITY_BILL_INTERFACE_H

class ElectricityBillInterface {
public:
    virtual ~ElectricityBillInterface() = default; // ����������� ����������
    virtual void setReading(int month, double reading) = 0; // ��������� ���������
    virtual void printMonthlyReport() const = 0; // ����� ������
    virtual double getTotalAmount() const = 0; // ��������� �������� �����
};

#endif