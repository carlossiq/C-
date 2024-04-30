#ifndef SALESP_H
#define SALESP_H

class SalesPerson
{
    public:
    SalesPerson();
    void getSalesFromUser();
    void setSales(int, double);
    void printtAnnualSales();

    private:
    double totalAnnualSales();
    double sales[12];
};

#endif