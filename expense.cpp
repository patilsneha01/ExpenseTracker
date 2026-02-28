#include "expense.h"

Expense::Expense(QString category, double amount, QDate date, QString note)
    : m_category(category),
    m_amount(amount),
    m_date(date),
    m_note(note)
{
}

QString Expense::GetCategory() const
{
    return m_category;
}

double Expense::GetAmount() const
{
    return m_amount;
}

QDate Expense::GetDate() const
{
    return m_date;
}

QString Expense::GetNote() const
{
    return m_note;
}
