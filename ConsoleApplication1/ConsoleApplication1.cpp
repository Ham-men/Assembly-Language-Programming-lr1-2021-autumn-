#include <iostream>
using namespace std;

//(15*A-2*A^2)/B^2

int main()
{
    int a = 0;
    int b = 0;
    int c2 = 0, c3 = 0;
    printf("vvod a = ");
    cin >> a;
    printf("\nvvod b>0 = ");
    cin >> b;

    _asm {
        mov eax, 15
        mul a
        mov ecx, eax //15*a

        mov eax, a
        mul a       //a*a

        mov ebx, 2
        mul ebx     //2*a

       
        sub ecx, eax
        mov ebx, ecx     //1-2 

        mov eax, b
        mul b
        mov ecx, eax    //b*b

        mov eax, ebx
        mov ebx, ecx
        mov edx,0
        
        div ebx
        mov c2, eax      //целое
        mov c3, edx      //остаток

    }
   
    printf("(15*%d-2*%d^2)/%d^2 = %d, %d", a, a, b, c2, c3);
    return 0;
}
