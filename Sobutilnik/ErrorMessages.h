#pragma once
#include <stdexcept>

namespace Errors {

	const char* const PasswordToSmall				= "������ ������ ���� ������ 8 ��������";
	const char* const PasswordFirstSymbol			= "������ ������ ������ ������ ���� ���������";
	const char* const PasswordNotEqual				= "������ �� ���������";
	const char* const LoginToSmall					= "����� ������ ���� ������ 5 ��������";
	const char* const AccountNotFound				= "������� � ������ ������� �� ������";
	const char* const EmailOrLoginNotUniq			= "������� � ����� email ��� ������� ��� ����������";
	const char* const LoginlNotUniq					= "������� � ����� ������� ��� ����������";
	const char* const AllFieldMustBeFilled			= "��� ���� ������ ���� ���������";
	const char* const UserTooYong					= "�� ������ ���� ������ 18 ��� ��� ������������� ������� ����������";
	const char* const DataWasSucsessfulyUpdated		= "������ ���� ������� ����������";
}
