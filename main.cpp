#include <QTextStream>
#include <QCoreApplication>
#include <iostream>
#include "Reg.h"

QTextStream cout(stdout);
QTextStream cin(stdin);
CompanyReg& registry = CompanyReg::getReg();

void CompanyStat(Company::type ComT)
{
    switch (ComT)
    {
    case Company::type::Government:
        cout << "Government Company: ";
        break;
    case Company::type::Private:
        cout << "Private Company: ";
        break;
    case Company::type::Municipal:
        cout << "Municipal Company: ";
        break;
    }

    cout << Qt::endl;

    for (int i = 0; i < registry.getRegSize(); i++)
    {
        Company* ptr = registry.getComIndex(i);
        if (ptr -> getCompanyType() == ComT)
        {
            cout << "Name: " << ptr -> getCompanyName() << Qt::endl;

            cout << "Owners: ";
                for (int j = 0; j < ptr -> getCompanyOwners().size(); j++)
                {
                    cout << ptr -> getCompanyOwners().operator[](j);
                if (j != ptr -> getCompanyOwners().size() - 1)
                    cout << ", ";
                }
                cout << Qt::endl;
        }
    }
}

// 2.
void CompanyByOwner(QString&& own)
{
    cout << own << "'s Companies: ";

    for(int i = 0; i < registry.getRegSize(); i++)
    {
        Company* ptr = registry.getComIndex(i);
        if(ptr->getCompanyOwners().contains(own))
        {
            cout << ptr -> getCompanyName() << Qt::endl;
        }
    }
}

