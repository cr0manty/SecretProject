#pragma once
#include <stdexcept>

namespace Errors {

	const char* const PasswordToSmall				= "������ ������ ���� ������ 8 ��������";
	const char* const PasswordFirstSymbol			= "������ ������ ������ ������ ���� ���������";
	const char* const PasswordNotEqual				= "������ �� ���������";
	const char* const LoginToSmall					= "����� ������ ���� ������ 5 ��������";
	const char* const AccountNotFound				= "������� � ������ ������� �� ������";
	const char* const EmailNotUniq					= "������� � ����� email ��� ����������";
	const char* const LoginNotUniq					= "������� � ����� ������� ��� ����������";
	const char* const AllFieldMustBeFilled			= "��� ���� ������ ���� ���������";
	const char* const UserTooYong					= "�� ������ ���� ������ 18 ��� ��� ������������� ������� ����������";
	const char* const DataWasSucsessfulyUpdated		= "������ ���� ������� ����������";
	const char* const NonFieldWasChanged			= "��� ���������� ��������� ���� �� 1 ���������";
	const char* const ConfirmDeletAcc				= "�� ����� ������ ������� ���� �������?\n������ �������� �� ��������!";
	const char* const ExitFromAcc					= "�� ����� ������ �����?";
	const char* const SucsessfulReg					= "����������� ������ �������!\n������ ������� � ���� �������";
}
