#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <QVector>
#include "expense.h"

class ExpenseManager
{
private:
    QVector<Expense> m_expenses;

public:
    void AddExpense(const Expense& expense);
    int GetCount() const;
    Expense GetExpense(int index) const;
    double GetTotalAmount() const;
};

#endif // EXPENSEMANAGER_H
