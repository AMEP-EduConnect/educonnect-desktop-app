#include "pch.h"
#include "TxIniciSessio.h"

TxIniciSessio::TxIniciSessio()
{
	usuariRepository = gcnew UsuariRepository();
}

Usuari^ TxIniciSessio::GetUsuariByPassUser(String^ username, String^ password)
{
	UsuariRepository^ user = gcnew UsuariRepository();
	return user->GetUsuariByPassUser(username, password);
}

bool TxIniciSessio::CheckUsername(String^ username, String^ password)
{
	Usuari^ checkuser = GetUsuariByPassUser(username, password);
	if (checkuser->username == username) {
		bool checkpassword = CheckPassword(checkuser, password);
		return checkpassword;
	}
	else return false;
}

bool TxIniciSessio::CheckPassword(Usuari^ checkuser, String^ password)
{
	if (checkuser->password == password) return true;
	else return false;
}