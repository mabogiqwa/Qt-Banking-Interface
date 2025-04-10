#include "transactionlist.h"

TransactionList& TransactionList::getInstance()
{
    static TransactionList instance;

    return instance;
}

void TransactionList::addTransaction(const Transaction& transaction)
{
    transactions.push_back(std::make_shared<Transaction>(transaction));

    qDebug() << transaction.formatOutput();
}

const std::vector<std::shared_ptr<Transaction>>& TransactionList::getTransactions() const
{
    return transactions;
}
