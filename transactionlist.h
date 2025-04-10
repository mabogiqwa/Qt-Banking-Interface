#ifndef TRANSACTIONLIST_H
#define TRANSACTIONLIST_H

#include "transaction.h"

class TransactionList
{
public:
    static TransactionList& getInstance();

    TransactionList(const TransactionList&) = delete;

    TransactionList& operator=(const TransactionList&) = delete;

    void addTransaction(const Transaction& transaction);

    const std::vector<std::shared_ptr<Transaction>>& getTransactions() const;

private:
    //Private constructor for Singleton
    TransactionList() = default;

    std::vector<std::shared_ptr<Transaction>> transactions;
};

#endif // TRANSACTIONLIST_H
