#include "bankingtransactionwindow.h"

BankingTransactionWindow::BankingTransactionWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Banking transactions");
    setFixedSize(250, 130);

    // Main vertical layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(10, 10, 10, 10);
    mainLayout->setSpacing(10);

    QHBoxLayout *dateLayout = new QHBoxLayout(this);

    QLabel *dateLabel = new QLabel("Date:", this);
    dateLayout->addWidget(dateLabel);

    QDate currentDate = QDate::currentDate();
    QString formattedDate = currentDate.toString("ddd MMM d yyyy");

    QLabel *currentDateLabel = new QLabel(formattedDate, this);

    dateLayout->addWidget(currentDateLabel);
    mainLayout->addLayout(dateLayout);

    // Date row


    // Amount row
    QHBoxLayout *amountLayout = new QHBoxLayout();
    QLabel *amountLabel = new QLabel("Amount:", this);
    m_amountSpinBox = new QDoubleSpinBox(this);
    m_amountSpinBox->setValue(0);
    m_amountSpinBox->setDecimals(2);
    m_amountSpinBox->setSingleStep(0.1);
    m_amountSpinBox->setRange(0, 1000000);

    amountLayout->addWidget(amountLabel);
    amountLayout->addWidget(m_amountSpinBox);
    mainLayout->addLayout(amountLayout);

    QHBoxLayout *balanceLayout = new QHBoxLayout();
    QLabel *balanceTextLabel = new QLabel("Current Balance:", this);
    balanceLabel = new QLabel("R0.00", this);

    balanceLayout->addWidget(balanceTextLabel);
    balanceLayout->addWidget(balanceLabel);

    // Button row
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QPushButton *depositButton = new QPushButton("Deposit", this);
    QPushButton *withdrawalButton = new QPushButton("Withdrawal", this);
    QPushButton *toFileButton = new QPushButton("To file", this);

    connect(depositButton, &QPushButton::clicked, this, &BankingTransactionWindow::onDeposit);
    connect(withdrawalButton, &QPushButton::clicked, this, &BankingTransactionWindow::onWithdrawal);
    connect(toFileButton, &QPushButton::clicked, this, &BankingTransactionWindow::onToFile);

    buttonLayout->addWidget(depositButton);
    buttonLayout->addWidget(withdrawalButton);
    buttonLayout->addWidget(toFileButton);
    mainLayout->addLayout(balanceLayout);
    mainLayout->addLayout(buttonLayout);
}

void BankingTransactionWindow::updateBalanceDisplay()
{
    balanceLabel->setText(QString("R%1").arg(currentBalance,0,'f',2));
}

void BankingTransactionWindow::onDeposit()
{
    double amount = m_amountSpinBox->value();
    currentBalance += amount;
    Transaction transaction(QDateTime::currentDateTime(), amount, TransactionType::DEPOSIT);
    TransactionList::getInstance().addTransaction(transaction);
    m_amountSpinBox->setValue(0);

    updateBalanceDisplay();
}

void BankingTransactionWindow::onWithdrawal()
{
    double amount = m_amountSpinBox->value();

    if (amount > currentBalance)
    {
        QMessageBox::warning(this,"Insufficient Funds","You do not have enough balance for this withdrawal.");
        return;
    }

    currentBalance -= amount;
    Transaction transaction(QDateTime::currentDateTime(), amount, TransactionType::WITHDRAWAL);
    TransactionList::getInstance().addTransaction(transaction);
    m_amountSpinBox->setValue(0);

    updateBalanceDisplay();
}

void BankingTransactionWindow::onToFile()
{
    const auto& transactions = TransactionList::getInstance().getTransactions();

    if (transactions.empty())
    {
        QDate currentDate = QDate::currentDate();
        QString fileName = QString("Transactions_%1.txt").arg(currentDate.toString("yyyyMMdd"));

        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&file);
            out << "Transaction History\n";
            out << "===================\n";
            out << "No transactions recorded.\n";
            file.close();

            QMessageBox::information(this, "File Created", QString("Empty transaction file created: %1").arg(fileName));
            return;
        } else {
            QMessageBox::warning(this, "Error", "Could not create file.");
            return;
        }
    }

    //If transactions exist we need to determine the file name based on the first transaction's date
    QDateTime firstTransactionDateTime = transactions.front()->getDateTime();
    QDate transactionDate = firstTransactionDateTime.date();
    QString fileName = QString("Transactions_%1.txt").arg(transactionDate.toString("yyyyMMdd"));

    QFile file(fileName);
    if (!file.open(QIODevice::Append | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "Could not open file for writing.");
        return;
    }

    QTextStream out(&file);

    if (file.size() == 0)
    {
        out << "Transaction History\n";
        out << "===================\n";
    }

    for (const auto& transactionPtr : transactions)
    {
        out << transactionPtr->formatOutput() << "\n";
    }

    file.close();

    QMessageBox::information(this, "Success", QString("Transactions saved to %1").arg(fileName));
}

BankingTransactionWindow::~BankingTransactionWindow()
{
}

