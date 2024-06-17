#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>

using namespace std;

void compress(string& str)
{
    istringstream stream(str);
    string word;
    string result;

    bool firstWord = true;
    while (stream >> word)
    {
        if (!firstWord)
        {
            result += " ";
        }
        result += word;
        firstWord = false;
    }

    // ���������� ������� ��������
    size_t leadingSpaces = 0;
    while (leadingSpaces < str.size() && str[leadingSpaces] == ' ')
    {
        ++leadingSpaces;
    }

    result = string(leadingSpaces, ' ') + result;
    str = result;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string str = "     �������      ���   �����      �������     ������������    ���-�� ��������                     ";
    compress(str);
    cout << "\"" << str << "\"" << endl;
    return 0;
}