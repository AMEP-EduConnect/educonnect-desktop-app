#include "pch.h"
#include "TxIniciSessio.h"


TxIniciSessio::TxIniciSessio()
{
	usuariRepository = gcnew UsuariRepository();
}

Usuari^ TxIniciSessio::GetUsuariByPassUser(String^ username, String^ password)
{
	
	return usuariRepository->GetUsuariByPassUser(username, password);
}

bool TxIniciSessio::CheckUsername(String^ username, String^ password)
{
	Usuari^ checkuser = GetUsuariByPassUser(username, password);
	if (checkuser->GetUsername() == username) {
		bool checkpassword = CheckPassword(checkuser, password);
		if(checkpassword) CurrentSession::Instance->LogNewUser(checkuser);
		return checkpassword;
	}
	else return false;
}

bool TxIniciSessio::CheckPassword(Usuari^ checkuser, String^ password)
{
	if (checkuser->GetPassword() == password) return true;
	else return false;
}

Int64^ TxIniciSessio::GetUserId(String^ username) 
{
	Usuari^ user = usuariRepository->GetUsuariByUser(username);

	if (user != nullptr) return user->GetUserId();

	else return nullptr;

}