#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ApplyStyle();
    ui->amountlineEdit->setPlaceholderText("Enter amount");
    ui->notelineEdit_2->setPlaceholderText("Optional note");
    // Add categories
    ui->categoryComboBox->addItem("Food");
    ui->categoryComboBox->addItem("Travel");
    ui->categoryComboBox->addItem("Shopping");
    ui->categoryComboBox->addItem("Bills");
    ui->categoryComboBox->addItem("Other");

    //table headers
    ui->expenseTable->setColumnCount(5);
    QStringList headers;
    headers << "Sr. No" << "Category" << "Amount" << "Date" << "Description";
    ui->expenseTable->setHorizontalHeaderLabels(headers);
    ui->expenseTable->horizontalHeader()->setStretchLastSection(true);

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::OnAddButtonClicked);
}

void MainWindow::OnAddButtonClicked()
{
    QString category = ui->categoryComboBox->currentText();
    double amount = ui->amountlineEdit->text().toDouble();
    QDate date = ui->dateEdit->date();
    QString note = ui->notelineEdit_2->text();

    Expense expense(category, amount, date, note);
    m_manager.AddExpense(expense);

    int row = ui->expenseTable->rowCount();
    ui->expenseTable->insertRow(row);

    ui->expenseTable->setItem(row, 0, new QTableWidgetItem(QString::number(row + 1)));
    ui->expenseTable->setItem(row, 1, new QTableWidgetItem(category));
    ui->expenseTable->setItem(row, 2, new QTableWidgetItem(QString::number(amount)));
    ui->expenseTable->setItem(row, 3, new QTableWidgetItem(date.toString("dd-MM-yyyy")));
    ui->expenseTable->setItem(row, 4, new QTableWidgetItem(note));
    ui->expenseTable->verticalHeader()->setVisible(false);

    double total = m_manager.GetTotalAmount();
    ui->totalLabel->setText("Total: " + QString::number(total));

    ui->amountlineEdit->clear();
    ui->notelineEdit_2->clear();
}

void MainWindow::ApplyStyle()
{
    this->setStyleSheet(
        "QMainWindow { background-color: #f4f6f9; }"

        "QTableWidget {"
        "background-color: white;"
        "gridline-color: #e0e0e0;"
        "border-radius: 10px;"
        "font-size: 14px;"
        "}"

        "QHeaderView::section {"
        "background-color: #4a90e2;"
        "color: white;"
        "padding: 6px;"
        "font-weight: bold;"
        "}"

        "QPushButton {"
        "background-color: #28a745;"
        "color: white;"
        "border-radius: 8px;"
        "padding: 6px 12px;"
        "}"

        "QPushButton:hover {"
        "background-color: #218838;"
        "}"
        );
}

MainWindow::~MainWindow()
{
    delete ui;
}
