#include "Company.h"

Company::Company(QString &name, QList<QString> &owners, double income, double area, int NumEmp)
{
    ComName = name;
    ComOwners = owners;
    ComIncome = income;
    ComArea= area;
    EmpNumber = NumEmp;
}

Company::~Company() {}

QString Company::getCompanyName()
{
    return ComName;
}

QList<QString> Company::getCompanyOwners()
{
    return ComOwners;
}

double Company::getCompanyIncome()
{
    return ComIncome;
}

double Company::getCompanyArea()
{
    return ComArea;
}

int Company::getEmpNumber()
{
    return EmpNumber;
}

GovernmentCompany::GovernmentCompany(QString &name, QList<QString> &holders, double income, double area, int NumEmp):
    Company(name, holders, income, area, NumEmp)
{
}

Company::type GovernmentCompany::getCompanyType()
{
    return type::Government;
}

double GovernmentCompany::getCompanyTax()
{
    double Income = getCompanyIncome()*0.05;
    double AreaIncome = getCompanyIncome()*0.03;
    double EmpIncome = getCompanyIncome()*0.02;
    return Income + AreaIncome + EmpIncome;
}

PrivateCompany::PrivateCompany(QString &name, QList<QString> &holders, double income, double area, int NumEmp):
    Company(name, holders, income, area, NumEmp)
{
}

Company::type PrivateCompany::getCompanyType()
{
    return type::Private;
}

double PrivateCompany::getCompanyTax()
{
    double Income = getCompanyIncome()*0.7;
    double AreaIncome = getCompanyIncome()*0.4;
    double EmpIncome = getCompanyIncome()*0.3;
    return (EmpIncome + AreaIncome)/Income;
}


MunicipalCompany::MunicipalCompany(QString &name, QList<QString> &holders, double income, double area, int NumEmp):
    Company(name, holders, income, area, NumEmp)
{
}

Company::type MunicipalCompany::getCompanyType()
{
    return type::Municipal;
}

double MunicipalCompany::getCompanyTax()
{
    double Income = getCompanyIncome()*0.4;
    double EmpIncome = getCompanyIncome()*0.3;
    return Income*EmpIncome/3;
}

















