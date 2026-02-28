#include "expensemanager.h"

void ExpenseManager::AddExpense(const Expense& expense)
{
    m_expenses.append(expense);
}

int ExpenseManager::GetCount() const
{
    return m_expenses.size();
}

Expense ExpenseManager::GetExpense(int index) const
{
    return m_expenses.at(index);
}

double ExpenseManager::GetTotalAmount() const
{
    double total = 0.0;

    for (const Expense& expense : m_expenses)
    {
        total += expense.GetAmount();
    }

    return total;
}
