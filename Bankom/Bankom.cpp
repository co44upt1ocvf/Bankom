#include <iostream>
#include <stdexcept>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int accountNumber, double initialBalance) {
        this->accountNumber = accountNumber;
        this->balance = initialBalance;
        this->interestRate = 0.0;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Сумма не может быть отрицательной или равной нулю");
        }
        this->balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Сумма не может быть отрицательной или равной нулю");
        }
        if (amount <= this->balance) {
            this->balance -= amount;
        }
        else {
            cout << "Недостаточно средств" << endl;
        }
    }

    double getBalance() {
        return this->balance;
    }

    double getInterest() {
        return this->balance * (this->interestRate / 100) * (1.0 / 12);
    }

    void setInterestRate(double rate) {
        if (rate < 0) {
            throw invalid_argument("Процент не может быть отрицательным");
        }
        this->interestRate = rate;
    }

    int getAccountNumber() {
        return this->accountNumber;
    }

    bool transfer(BankAccount& destinationAccount, double amount) {
        if (amount <= 0) {
            throw invalid_argument("Сумма не может быть отрицательной или равной нулю");
        }
        if (amount <= this->balance) {
            this->balance -= amount;
            destinationAccount.deposit(amount);
            return true;
        }
        else {
            cout << "Недостаточно средств для перевода" << endl;
            return false;
        }
    }
};

int chooseaccount() {
    int acc;

    cout << "Выбирите аккаунт для проведения операции: ";
    cin >> acc;

    return acc;
}

int main() {
    setlocale(LC_ALL, "RUS");

    cout << "Создайте два счёта:\n" << endl;

    try {
        int accountNumber1, accountNumber2;
        double initialBalance1, initialBalance2;

        cout << "Введите номер для первого счёта: ";
        cin >> accountNumber1;
        if (cin.fail()) {
            throw runtime_error("Неверный ввод номера счёта");
        }
        else if (accountNumber1 <= 0) {
            throw invalid_argument("Номер аккаунта не может быть отрицательным или равным нулю");
        }

        initialBalance1 = 0.0;
        cout << "Начальный баланс для счёта: " << initialBalance1 << " руб." << endl;

        cout << "\nВведите номер для второго счета: ";
        cin >> accountNumber2;
        if (cin.fail()) {
            throw runtime_error("Неверный ввод номера счёта");
        }
        else if (accountNumber2 <= 0) {
            throw invalid_argument("Номер аккаунта не может быть отрицательным или равным нулю");
        }
        else if (accountNumber2 == accountNumber1) {
            throw invalid_argument("Номер счёта не может совпадать");
        }

        initialBalance2 = 0.0;
        cout << "Начальный баланс для счёта: " << initialBalance2 << " руб." << endl;

        BankAccount account1(accountNumber1, initialBalance1);
        BankAccount account2(accountNumber2, initialBalance2);

        while (true) {
            int choice;
            double rate, amount;

            cout << "\nВыберите операцию:\n"
                "\t1. Внести средства\n"
                "\t2. Снять средства\n"
                "\t3. Посмотреть баланс счёта\n"
                "\t4. Сумма процентов\n"
                "\t5. Обновление ставки\n"
                "\t6. Номер счёта\n"
                "\t7. Перевод между счётами\n"
                "\tЕсли вы хотите выйти нажмите - \"8\"\n"
                "Операция: " << endl;
            cin >> choice;
            if (cin.fail()) {
                throw runtime_error("Неверный ввод номера операции");
            }

            switch (choice) {
            case 1:
                switch (chooseaccount()) {
                case 1:
                    cout << "Введите сумму для зачисления: ";
                    cin >> initialBalance1;
                    if (cin.fail()) {
                        throw runtime_error("Неверный ввод суммы");
                    }
                    account1.deposit(initialBalance1);
                    cout << "Баланс счёта: " << account1.getBalance() << " руб." << endl;
                    break;
                case 2:
                    cout << "Введите сумму для зачисления: ";
                    cin >> initialBalance2;
                    if (cin.fail()) {
                        throw runtime_error("Неверный ввод суммы");
                    }
                    account2.deposit(initialBalance2);
                    cout << "Баланс счёта: " << account2.getBalance() << " руб." << endl;
                    break;
                default:
                    cout << "Такого выбора не существует..." << endl;
                    break;
                }
                break;
            case 2:
                switch (chooseaccount()) {
                case 1:
                    cout << "Введите сумму для снятия: ";
                    cin >> initialBalance1;
                    if (cin.fail()) {
                        throw runtime_error("Неверный ввод суммы");
                    }
                    account1.withdraw(initialBalance1);
                    cout << "Баланс счёта: " << account1.getBalance() << " руб." << endl;
                    break;
                case 2:
                    cout << "Введите сумму для снятия: ";
                    cin >> initialBalance2;
                    if (cin.fail()) {
                        throw runtime_error("Неверный ввод суммы");
                    }
                    account2.withdraw(initialBalance2);
                    cout << "Баланс счёта: " << account2.getBalance() << " руб." << endl;
                    break;
                default:
                    cout << "Такого выбора не существует..." << endl;
                    break;
                }
                break;
            case 3:
                switch (chooseaccount()) {
                case 1:
                    cout << "Баланс счёта: " << account1.getBalance() << " руб." << endl;
                    break;
                case 2:
                    cout << "Баланс счёта: " << account2.getBalance() << " руб." << endl;
                    break;
                default:
                    cout << "Такого выбора не существует..." << endl;
                    break;
                }
                break;
            case 4:
                switch (chooseaccount()) {
                case 1:
                    cout << "Сумма процентов, заработанных на счёте: " << account1.getInterest() << "%" << endl;
                    break;
                case 2:
                    cout << "Сумма процентов, заработанных на счёте: " << account2.getInterest() << "%" << endl;
                    break;
                default:
                    cout << "Такого выбора не существует..." << endl;
                    break;
                }
                break;
            case 5:
                switch (chooseaccount()) {
                case 1:
                    cout << "Введите новую процентную ставку: ";
                    cin >> rate;
                    if (cin.fail()) {
                        throw runtime_error("Неверный ввод процентной ставки");
                    }
                    account1.setInterestRate(rate);
                    cout << "Процентная ставка: " << rate << "%" << endl;
                    break;
                case 2:
                    cout << "Введите новую процентную ставку: ";
                    cin >> rate;
                    if (cin.fail()) {
                        throw runtime_error("Неверный ввод процентной ставки");
                    }
                    account2.setInterestRate(rate);
                    cout << "Процентная ставка: " << rate << "%" << endl;
                    break;
                default:
                    cout << "Такого выбора не существует..." << endl;
                    break;
                }
                break;
            case 6:
                switch (chooseaccount()) {
                case 1:
                    cout << "Номер аккаунта: " << account1.getAccountNumber() << endl;
                    break;
                case 2:
                    cout << "Номер аккаунта: " << account2.getAccountNumber() << endl;
                    break;
                default:
                    cout << "Такого выбора не существует..." << endl;
                    break;
                }
                break;
            case 7:
                switch (chooseaccount()) {
                case 1:
                    cout << "Введите сумму для перевода с счёта 1 на счёт 2: ";
                    cin >> amount;
                    if (cin.fail()) {
                        throw runtime_error("Неверный ввод суммы перевода");
                    }

                    account1.transfer(account2, amount);
                    if (true) {
                        cout << "\nБалансы после перевода:" << endl;
                        cout << "Баланс первого счёта: " << account1.getBalance() << " руб." << endl;
                        cout << "Баланс второго счёта: " << account2.getBalance() << " руб." << endl;
                    }
                    break;
                case 2:
                    cout << "Введите сумму для перевода с счёта 2 на счёт 1: ";
                    cin >> amount;
                    if (cin.fail()) {
                        throw runtime_error("Неверный ввод суммы перевода");
                    }

                    account2.transfer(account1, amount);
                    if (true) {
                        cout << "\nБалансы после перевода:" << endl;
                        cout << "Баланс первого счёта: " << account1.getBalance() << " руб." << endl;
                        cout << "Баланс второго счёта: " << account2.getBalance() << " руб." << endl;
                    }
                    break;
                default:
                    cout << "Такого выбора не существует..." << endl;
                    break;
                }
                break;
            case 8:
                exit(0);
            default:
                cout << "Такого выбора не существует..." << endl;
                break;
            }
        }
    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}