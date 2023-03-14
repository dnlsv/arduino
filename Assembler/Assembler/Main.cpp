#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, ".UTF8");
    int y = 0, x, N, res_asm = 0;
    cout << "Введите x" << endl;
    cin >> x;
    cout << "Введите N" << endl;
    cin >> N;
    for (int i = 1; i <= N; i++)
        y = y + x * x;
    cout << "y = " << y << endl;

    __asm
    {
        mov eax, x
        mul eax // ax = x*x
        mov ebx, N
        mov ecx, 0
        mov edx, 0
        metka_1:
        add ecx, eax  // ax = y + x*x
            add edx, 1
            cmp ebx, edx
            je metka_2
            jmp metka_1
            metka_2 :
        mov res_asm, ecx
    }
    cout << "y = " << res_asm << endl;

    system("pause");
}
