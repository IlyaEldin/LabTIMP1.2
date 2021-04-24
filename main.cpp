#include "CesarDop.h"
#include <stdio.h>
#include <iostream>
#include <cctype>
#include <locale>
using namespace std;
bool KeyisValid(const int& s)
{
        if (s>0)
    return true;
    return false;
}
bool isValid(const wstring& s)
{
    for(auto c:s)
        if (!iswalpha(c) || !iswupper(c))
            return false;
    return true;
}
int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    wstring text;
    unsigned op;
    wcout<<L"Шифратор готов. Введите ключ: ";
    int key;
    wcin>>key;
    Cs skey(key);
    do {
        wcout<<L"Шифратор готов. Выберите операцию (0-выход, 1-зашифровка, 2-расшифровка): ";
        wcin>>op;
        if (op > 2) {
            wcout<<L"Операция не выбрана\n";
        } else if (op >0) {
            wcout<<L"Шифратор готов. Введите текст: ";
            wcin>>text;
            if (isValid(text)) {
                if (op==1) {
                    wcout<<L"Зашифрованный текст: "<<skey.Coder(skey, text)<<endl;
                } else {
                    wcout<<L"Введите ключ для расшифровки: ";
                    wcin>>key;
                    wcout<<L"Расшифрованный текст:"<<skey.Decoder(key, text)<<endl;
                }
            } else {
                wcout<<L"Операция не выполнена: неправильный формат текста\n";
            }
        }
    } while ((op!=0) && KeyisValid(key));
    return 0;
}
