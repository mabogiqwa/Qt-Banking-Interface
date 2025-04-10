# Simple Transaction Manager
This is a simple desktop application that was built using Qt Creator and it can be utilized to manage banking transactions such as deposits and withdrawals. It also has the capability to save transaction history into a text file.

## Installation Instructions
To set up the project locally you need to install the latest version of mingw(C++ compiler), download Qt installer and select your specifications to install Qt Creator. You will also need to install CMake.

## Features
- Records deposits and withdrawals
- Real-time balance updates
- Exports transaction history to text file
- Transaction timestamping
- Simple and intuitive UI.

## Components
- Transaction: This class represents individual transactions
- TransactionList: Singleton class that manages all transactions
- BankingTransactionWindow: Responsible for displaying UI for handling user interactions.

## Usage Guide
### 1. Deposit Money:
   - Enter an amount either by typing it in or using the spinbox
   - Click on the deposit button and the current balance will update automatically
     
### 2. Withdraw Money:
   - Enter an amount either by typing it in or using the spinbox
   - Click on the withdrawal button and if your balance is greater than your withdrawal, the balance with update
   - If funds are inefficient then you will receive a warning message
     
### 3. Save Transactions to File:
   - Click on the "To file" button
   - A text file with the name "Transactions_YYYYMMDD.txt" will be created

## Contributing
Feel free to submit a pull request

## Future Improvements
- Data persistance between sessions
- Transaction categories and filtering
- Enhanced categorical transaction reporting and statistics
