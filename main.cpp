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
void CompanyByOwner(QString own)
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

// 3.
void CompData()
{
    for(int k = Company::type::Government; k <= Company::type::Municipal; k++)
    {
        int n = 0;
        double AverageIncome = 0;
        double AverageArea = 0;
        double AverageNumber = 0;

        switch (k)
        {
        case Company::type::Government:
            cout << "Government Company Data: ";
            break;
        case Company::type::Private:
            cout << "Private Company Data: ";
            break;
        case Company::type::Municipal:
            cout << "Municipal Company Data: ";
            break;
        }
        cout << Qt::endl;

        for (int i = 0; i < registry.getRegSize(); i++)
        {
            Company* ptr = registry.getComIndex(i);
            if (k == ptr -> getCompanyType())
            {
                AverageIncome += ptr -> getCompanyIncome();
                AverageArea += ptr -> getCompanyArea();
                AverageNumber += ptr -> getEmpNumber();
                n++;
            }
        }
        cout << "Average Income = " << AverageIncome / n << Qt::endl;
        cout << "Average Area = " << AverageArea / n << Qt::endl;
        cout << "Average Emp Numbers = " << AverageNumber / n << Qt::endl;
        cout << Qt::endl;
    }
}

int main(int argc, char *argv[])
{
      QCoreApplication a(argc, argv);
      QList<QString> owner1, owner2, owner3;
      QString name1, name2, name3 ;

      name1 = "Rosatom";
      owner1 << "Vladimir Putin";
      Company* Putin = new GovernmentCompany(name1, owner1, 64500000000, 266000, 154741);

      name2 = "Jack Daniel's";
      owner2 << "Jeff Arnett";
      Company* Jackie = new PrivateCompany(name2, owner2, 74124999234, 341000, 467899);

      name2 = "Bryansk City Center Earth";
      owner3 << "Slepenko Galina";
      Company* bryansk = new MunicipalCompany(name3, owner3, 120001344, 14234, 32134);


      registry.AddCompany(*Putin);
      registry.AddCompany(*Jackie);
      registry.AddCompany(*bryansk);

      int ty = 0;

      cout << "Choose company's type: 0 - Government, 1 - Private, 2 - Municipal " << Qt::endl;
      cin >> ty;

      CompanyStat(Company::type(ty));

      cout << Qt::endl;

      std::string yourowner;

      cout << "Choose your owner: " << Qt::endl;
      std::getline(std::cin, yourowner);

      cout << Qt::endl;

      CompanyByOwner(QString::fromStdString(yourowner));

      cout << Qt::endl;

      CompData();

      return a.exec();
}
