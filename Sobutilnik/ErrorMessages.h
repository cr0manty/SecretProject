#pragma once
#include <stdexcept>

namespace Errors {

	const char* const PasswordToSmall				= "Пароль должен быть больше 8 символов";
	const char* const PasswordFirstSymbol			= "Первый символ пароля должен быть заглавным";
	const char* const PasswordNotEqual				= "Пароли не совпадают";
	const char* const LoginToSmall					= "Логин должен быть больше 5 символов";
	const char* const AccountNotFound				= "Аккаунт с такими данными не найден";
	const char* const EmailNotUniq					= "Аккаунт с таким email уже существует";
	const char* const LoginNotUniq					= "Аккаунт с таким логином уже существует";
	const char* const AllFieldMustBeFilled			= "Все поля должны быть заполнены";
	const char* const UserTooYong					= "Вы должны быть старше 18 лет для использования данного приложения";
	const char* const DataWasSucsessfulyUpdated		= "Данные были успешно обновленны";
	const char* const NonFieldWasChanged			= "Для сохранения требуется хотя бы 1 изменение";
	const char* const ConfirmDeletAcc				= "Вы точно хотите удалить свой аккаунт?\nДанное действие не обратимо!";
	const char* const ExitFromAcc					= "Вы точно хотите выйти?";
	const char* const SucsessfulReg					= "Регистрация прошла успешно!\nТеперь войдите в свой аккаунт";
}
