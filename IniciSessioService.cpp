#include "pch.h"
#include "IniciSessioService.h"


IniciSessioService::IniciSessioService()
{
	usuariRepository = gcnew UsuariRepository();
	usuariRolRepository = gcnew UsuariRolRepository();
	credentialMagamentService = gcnew CredentialManagementService();
}

Usuari^ IniciSessioService::GetUsuariByUser(String^ username)
{
	return usuariRepository->GetUsuariByUser(username);
}

Usuari^ IniciSessioService::GetUsuariById(Int64^ id)
{
	return this->usuariRepository->GetUsuariById(id);
}

bool IniciSessioService::CheckUsername(String^ username, String^ password)
{
	Usuari^ checkuser = GetUsuariByUser(username);
	if (checkuser->GetUsername() == username) {
		bool checkpassword = CheckPassword(checkuser->GetPassword(), password);
		if (checkpassword) {
			Int64^ id_rol = usuariRolRepository->GetRolId(checkuser->GetUserId());
			CurrentSession::Instance->LogNewUser(checkuser,id_rol);
		}
		return checkpassword;
	}
	else return false;
}

bool IniciSessioService::CheckPassword(String^ user_password, String^ password)
{
	return credentialMagamentService->VerifyPassword(password, user_password);
}

Int64^ IniciSessioService::GetUserId(String^ username) 
{
	Usuari^ user = usuariRepository->GetUsuariByUser(username);

	if (user != nullptr) return user->GetUserId();

	else return nullptr;

}