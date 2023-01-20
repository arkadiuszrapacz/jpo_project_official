#include <iostream>
#include "calculator.h"
#include <iomanip>
#include <bitset>
#include <sstream>
#include <cmath>
#include <cstdlib>

using namespace std;

void Calculator::hello()
{
    cout << endl << "Witam w kalkulatorze dla elektronikow. " << endl;
    cout << "---------------------------------------" << endl;
    cout << "Co moge dla ciebie zrobic?" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Opcje:" << endl;
    cout << "---------------------------------------" << endl;
    cout << "1. Dodawanie" << endl;
    cout << "2. Odejmowanie" << endl;
    cout << "3. Mnozenie" << endl;
    cout << "4. Dzielenie" << endl;
    cout << "5. Konwersja liczb dziesietnych" << endl;
    cout << "6. Wyjdz" << endl;
    cout << endl;
}

void Calculator::setVar1()
{
    cout << "Podaj pierwsza wartosc: ";
    cin >> p_var1;
    if (cin.fail())
    {
        cout << "Nalezy wpisac liczbe!" << endl;
        flag = false;
    }
}

void Calculator::setVar2()
{
    cout << "Podaj druga wartosc: ";
    cin >> p_var2;
    if (cin.fail())
    {
        cout << "Nalezy wpisac liczbe!" << endl;
        flag = false;
    }
}

void Calculator::setOperation()
{
    char operation;
    cout << "Wybierz operacje (podaj numer operacji): ";
    cin >> operation;
    cout << endl;
    p_operation = operation;
}

char Calculator::getOperation()
{
    return p_operation;
}

void Calculator::calculate()
{
    stringstream resultStream;
    resultStream << fixed << setprecision(2);

    switch (p_operation)
    {
    case '1':
        resultStream << p_var1 + p_var2;
        break;
    case '2':
        resultStream << p_var1 - p_var2;
        break;
    case '3':
        resultStream << p_var1 * p_var2;
        break;
    case '4':
        if (p_var2 == 0)
            cout << "Nie mozna dzielic przez 0!" << endl;
        else
            resultStream << p_var1 / p_var2;
        break;
    case '5':
        resultStream << p_var1;
        break;
    case '6':
        exit(0);
    default:
        cout << "Invalid operation" << endl;
        break;
    }
    p_oper_result = resultStream.str();
}

string Calculator::getResult()
{
    return p_oper_result;
}

string Calculator::toHex()
{
    stringstream resultStream;
    long long int resultInt;

    resultStream << p_oper_result;
    resultStream >> resultInt;
    resultStream.clear();

    resultStream << "\t\t\t0x" << hex << resultInt;

    return resultStream.str();
}

string Calculator::toBin()
{
    stringstream resultStream;
    long long int resultInt;

    resultStream << p_oper_result;
    resultStream >> resultInt;
    resultStream.clear();

    resultStream << "\t\t\t0b" << bitset<64>(resultInt);

    return resultStream.str();
}

string Calculator::toOct()
{
    stringstream resultStream;
    long long int resultInt;

    resultStream << p_oper_result;
    resultStream >> resultInt;
    resultStream.clear();

    resultStream << "\t\t\t0" << oct << resultInt;

    return resultStream.str();
}