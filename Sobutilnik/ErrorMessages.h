#pragma once
#include <stdexcept>

namespace Errors {

	const char* const PasswordToSmall				= "������ ������ ���� ������ 8 ��������";
	const char* const PasswordFirstSymbol			= "������ ������ ������ ������ ���� ���������";
	const char* const PasswordNotEqual				= "������ �� ���������";
	const char* const PasswordIsEmpty				= "������ �� ����� ���� ������";
	const char* const LoginToSmall					= "����� ������ ���� ������ 5 ��������";
	const char* const FirstnameEmpty				= "��� �� ����� ���� ������";
	const char* const SurnameEmpty					= "������� �� ����� ���� ������";
	const char* const SexNotChoosen					= "��� ������ ���� ������!";
	const char* const AccountNotFound				= "������� � ������ ������� �� ������";
	const char* const EmailNotUniq					= "������� � ����� email ��� ����������";
	const char* const LoginlNotUniq					= "������� � ����� ������� ��� ����������";
}
