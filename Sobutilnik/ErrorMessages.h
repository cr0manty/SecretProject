#pragma once
#include <stdexcept>

namespace Errors {

	const char* const PasswordToSmall				= "Пароль должен быть больше 8 символов";
	const char* const PasswordFirstSymbol			= "Первый символ пароля должен быть заглавным";
	const char* const PasswordNotEqual				= "Пароли не совпадают";
	const char* const PasswordIsEmpty				= "Пароль не может быть пустой";
	const char* const LoginToSmall					= "Логин должен быть больше 5 символов";
	const char* const FirstnameEmpty				= "Имя не может быть пустым";
	const char* const SurnameEmpty					= "Фамилия не может быть пустой";
	const char* const SexNotChoosen					= "Пол должен быть выбран!";
	const char* const AccountNotFound				= "Аккаунт с такими данными не найден";
	const char* const EmailNotUniq					= "Аккаунт с таким email уже существует";
	const char* const LoginlNotUniq					= "Аккаунт с таким логином уже существует";
}
