#include "TemplateElectricityBill.h"

int main() {
    try {
        // Создаем объект для учета целочисленных показаний
        TemplateElectricityBill<int> intBill(5, 2023, 3);
        intBill.setReading(3, 100);
        intBill.setReading(2, 200);
        intBill.setReading(4, 150);
        intBill.printMonthlyReport();

        // Создаем объект для учета вещественных показаний
        TemplateElectricityBill<double> doubleBill(3.5, 2024, 6);
        doubleBill.setReading(6, 120.5);
        doubleBill.setReading(7, 300.75);
        doubleBill.setReading(8, 450.25);
        doubleBill.printMonthlyReport();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
