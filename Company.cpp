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

void Company::setCompanyName(const QString &value)
{
    ComName = value;
}

QList<QString> Company::getCompanyOwners()
{
    return ComOwners;
}

void Company::setCompanyOwners(const QList<QString> &value)
{
    ComOwners = value;
}

double Company::getCompanyIncome()
{
    return ComIncome;
}

void Company::setCompanyIncome(double value)
{
    ComIncome = value;
}

double Company::getCompanyArea()
{
    return ComArea;
}

void Company::setCompanytArea(double value)
{
   ComArea = value;
}

int Company::getEmpNumber()
{
    return EmpNumber;
}

void Company::setEmpNumber(int value)
{
    EmpNumber = value;
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

















