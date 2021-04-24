#include "CesarDop.h"

Cs::Cs(int k)
{
    this->k=k;
}
wstring Cs::Coder(Cs w, wstring& s)
{
    wstring code;
    int height;
    if (s.size()%w.k!=0) {
        height=s.size()/w.k+1;
    } else {
        height=s.size()/w.k;
    }
    wchar_t a[height][w.k];
    int k=0;
    for (int i=0; i<height; i++) {
        for (int j=0; j<w.k; j++) {
            if (k<s.size()) {
                a[i][j]=s[k];
                k++;
            } else a[i][j]=' ';
        }
    }
    for (int i=0; i<w.k; i++) {
        for (int j=0; j<height; j++) {
            code+=a[j][i];
        }
    }
    return code;
}
wstring Cs::Decoder(int w, wstring& s)
{
    int height;
    if (s.size()%w!=0) {
        height=s.size()/w+1;
    } else {
        height=s.size()/w;
    }
    wchar_t a[height][w];
    int k=0;
    for (int i=0; i<w; i++) {
        for (int j=0; j<height; j++) {
            a[j][i]=s[k];
            k++;
        }
    }
    wstring decode;
    for (int i=0; i<height; i++) {
        for (int j=0; j<w; j++) {
            decode+=a[i][j];
        }
    }
    return decode;
}
