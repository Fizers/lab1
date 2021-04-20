#ifndef COMPANY_H
#define COMPANY_H

#include <QString>
#include <QList>

class Company
{
private:
    QString ComName;
    QList<QString> ComOwners;
    double ComIncome;
    double ComArea;
    int EmpNumber;
public:
    enum type
    {
        Government,
        Private,
        Municipal
    };
    Company(QString &name, QList<QString> &owners, double income, double area, int NumEmp);
    virtual ~Company();
    virtual type getCompanyType() = 0;
    virtual double getCompanyTax() = 0;
    QString getCompanyName();
    QList<QString> getCompanyOwners();
    double getCompanyIncome();
    double getCompanyArea();
    int getEmpNumber();
};

class GovernmentCompany : public Company
{
public:
    GovernmentCompany(QString &name, QList<QString> &owners, double income, double area, int NumEmp);
    type getCompanyType();
    double getCompanyTax();
};

class PrivateCompany : public Company
{
public:
    PrivateCompany(QString &name, QList<QString> &owners, double income, double area, int NumEmp);
    type getCompanyType();
    double getCompanyTax();
};

class MunicipalCompany : public Company
{
public:
    MunicipalCompany(QString &name, QList<QString> &owners, double income, double area, int NumEmp);
    type getCompanyType();
    double getCompanyTax();
};



#endif



