/*

Esercizio 14
Scrivere un programma che dato un carattere in ingresso, lo trasforma in un altro
carattere, che si trova OFFSET posizioni più avanti nell’alfabeto.
(per esempio con OFFSET = 4, il carattere 'a' diventa 'e' oppure il carattere ‘z’ diventa ‘d’).
L'alfabeto considerato è:
ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
Per esempio, con OFFSET = 4, la lettera 'X' diventa 'b'.
La complessità del programma sta nel fatto che nella codifica ASCII le sequenze 'A'..'Z' e
'a'..'z' (viene prima la sequenza di caratteri maiuscoli) non sono consecutive, ma tra loro
c'è un altro insieme di caratteri, per cui occorre spezzare il programma in 2 “if”.
Input: un carattere da convertire
Output: il carattere convertito
Si riporta porzione del codice ASCII:
032 0x20 056 0x38 8 080 0x50 P 104 0x68 h
033 0x21 ! 057 0x39 9 081 0x51 Q 105 0x69 i
034 0x22 " 058 0x3a : 082 0x52 R 106 0x6a j
035 0x23 # 059 0x3b ; 083 0x53 S 107 0x6b k
036 0x24 $ 060 0x3c < 084 0x54 T 108 0x6c l
037 0x25 % 061 0x3d = 085 0x55 U 109 0x6d m
038 0x26 & 062 0x3e > 086 0x56 V 110 0x6e n
039 0x27 ' 063 0x3f ? 087 0x57 W 111 0x6f o
040 0x28 ( 064 0x40 @ 088 0x58 X 112 0x70 p
041 0x29 ) 065 0x41 A 089 0x59 Y 113 0x71 q
042 0x2a * 066 0x42 B 090 0x5a Z 114 0x72 r
043 0x2b + 067 0x43 C 091 0x5b [ 115 0x73 s
044 0x2c , 068 0x44 D 092 0x5c \ 116 0x74 t
045 0x2d - 069 0x45 E 093 0x5d ] 117 0x75 u
046 0x2e . 070 0x46 F 094 0x5e ^ 118 0x76 v
047 0x2f / 071 0x47 G 095 0x5f _ 119 0x77 w
048 0x30 0 072 0x48 H 096 0x60 ` 120 0x78 x
049 0x31 1 073 0x49 I 097 0x61 a 121 0x79 y
050 0x32 2 074 0x4a J 098 0x62 b 122 0x7a z
051 0x33 3 075 0x4b K 099 0x63 c 123 0x7b {
052 0x34 4 076 0x4c L 100 0x64 d 124 0x7c |
053 0x35 5 077 0x4d M 101 0x65 e 125 0x7d }
054 0x36 6 078 0x4e N 102 0x66 f 126 0x7e ~
055 0x37 7 079 0x4f O 103 0x67 g 127 0x7f 􀀀

*/

#include <iostream>

using namespace std;

int main()
{
	char c = 0;
	int offset = 0;
	
	do
	{
		cout << "inserire un carattere da convertire (maiuscolo o minuscolo dell'alfabeto): ";
		cin >> c;
		if(!((c>=0x41 && c<=0x5a) || (c>=0x61 && c<=0x7a)))
		{
			cout << "carattere non idoneao - riprovare" << endl;
		}
	}while(!((c>=0x41 && c<=0x5a) || (c>=0x61 && c<=0x7a)));

	do
	{
		cout << "inserire un valore per l'offset: ";
		cin >> offset;
		if((offset>52)||(offset<(-52)))
		{
			cout << "valore non idoneao - riprovare" << endl;
		}
	}while((offset>52)||(offset<(-52)));

    char temp = c;
    if(offset>0)
    {
        for(int i=0; i<offset; i++)
        {
            temp++;
            if(temp==0x5b)
            {
                offset += 6;
                break;
            }
        }
    }
    else if(offset<0)
    {
        for(int i=0; i>offset; i--)
        {
            temp--;
            if(temp==0x60)
            {
                offset -= 6;
                break;
            }
        }
    }

	cout << "risultato conversione: " << char(c + offset) << endl;

	return 0;
}