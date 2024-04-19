#include "pch.h"
#include "RegistreService.h"
#include "CredentialManagementService.h"

RegistreService::RegistreService()
{
	usuariRepository = gcnew UsuariRepository();
	usuariRolRepository = gcnew UsuariRolRepository();
	credentialMagamentService = gcnew CredentialManagementService();
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
	String ^hash = credentialMagamentService->HashPassword(password);
	id = this->usuariRepository->CreateUser(username, email, name, hash);
	Int64^ id_rol = 2LL;
	return this->usuariRolRepository->CreateUserRol(id,id_rol);
}