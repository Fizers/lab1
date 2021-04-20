#include "Reg.h"

CompanyReg::CompanyReg() {}

CompanyReg::~CompanyReg()
{
    while(!ComList.empty())
    {
       delete ComList.takeFirst();
    }
}

void CompanyReg::AddCompany(Company& company)
{
    ComList.append(&company);
}

Company* CompanyReg::getComIndex(int index)
{
    return ComList.at(index);
}

int CompanyReg::getRegSize()
{
    return ComList.size();
}

CompanyReg& CompanyReg::getReg()
{
    static CompanyReg reg;
    return reg;
}
