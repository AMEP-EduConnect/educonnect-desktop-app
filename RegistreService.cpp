#include "pch.h"
#include "RegistreService.h"


RegistreService::RegistreService()
{
	usuariRepository = gcnew UsuariRepository();
}

bool RegistreService::CheckUsername(String^ username)
{
	return this->usuariRepository->CheckUsuariByUser(username);
}

bool RegistreService::CheckEmail(String^ email)
{
    return this->usuariRepository->CheckUsuariByEmail(email);
}

bool RegistreService::CreateUser(String^ username, String^ email, String^ name, String^ password)
{
	Int64^ id;
	id = this->usuariRepository->CreateUser(username, email, name, password);
	return this->usuariRepository->CreateUserRol(id);
}