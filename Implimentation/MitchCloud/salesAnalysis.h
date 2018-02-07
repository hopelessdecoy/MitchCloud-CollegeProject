#ifndef SALESANALYSIS_H
#define SALESANALYSIS_H

#include "inventory.h"

class salesAnalysis
{
    public:
        salesAnalysis();
        ~salesAnalysis();

        float getSales();
        float getBreakEvenProfit();
        float getOverhead();

        void addOverhead(float cost);
        void addSales(float profit);

        void writeToFile();

    protected:

    private:
        float totalSales, overhead, breakinEven;

        void setBreakEven();
        void readFrFile();
};

#endif // SALESANALYSIS_H
