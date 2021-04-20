#ifndef REG_H
#define REG_H
#include "Company.h"
#include <QList>

class CompanyReg
{
private:
    QList<Company*> ComList;
    CompanyReg();
public:
    ~CompanyReg();
    CompanyReg(const CompanyReg&) = delete;
    void AddCompany(Company& Company);
    Company* getComIndex(int index);
    int getRegSize();
    static CompanyReg& getReg();
};

#endif // REG_H
