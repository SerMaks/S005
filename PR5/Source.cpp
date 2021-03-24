#include <iostream>

int main()
{
	std::cout << "¬ведите данные:\n";
	char s1[255];
	char s2[255];
	char f[] = "%s";
	char fd[] = "%d\n";

	_asm {
		//вводим строку, в которой будем искать
		lea ebx, s1
		push ebx
		lea ecx, f
		push ecx
		call scanf
		add esp, 8
		//вводим подстроку дл€ поиска
		lea ebx, s2
		push ebx
		lea ecx, f
		push ecx
		call scanf
		add esp, 8
		//подготовка к поиску
		lea ebx, s1
		dec ebx
		lea edx, s2
		dec edx
		mov ecx, -1
		push ecx
		//поиск индекса подстроки
		b1:
		inc ebx
		inc ecx
		mov al, [ebx]
		cmp al, 0
		jz end
		inc edx
		mov ah, [edx]
		cmp ah, 0
		jz end
		cmp al, ah
		jz b2
		lea edx, s2
		dec edx
		add esp, 4
		mov eax, -1
		push eax
		jmp b1
		b2:
		pop eax
		cmp eax, -1
		jg skip
		push ecx
		jmp b1
		skip:
		push eax
		jmp b1

		end:
		lea ebx, fd
		push ebx
		call printf
		add esp, 8
	}
}