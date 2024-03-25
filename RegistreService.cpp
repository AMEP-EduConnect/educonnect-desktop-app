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
	return this->usuariRepository->CreateUser(username, email, name, password);
}