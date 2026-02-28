#ifndef EXPENSE_H
#define EXPENSE_H

#include <QString>
#include <QDate>

class Expense
{
private:
    QString m_category;
    double m_amount;
    QDate m_date;
    QString m_note;

public:
    Expense(QString category, double amount, QDate date, QString note);

    QString GetCategory() const;
    double GetAmount() const;
    QDate GetDate() const;
    QString GetNote() const;
};

#endif // EXPENSE_H
