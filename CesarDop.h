#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Cs
{
private:
    int k;
public:
    Cs(int k);
    Cs()=delete;
    wstring Coder(Cs w, wstring& s);
    wstring Decoder(int w, wstring& s);
};
