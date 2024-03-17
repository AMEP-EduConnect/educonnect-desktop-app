#include "pch.h"
#include "TxRegistre.h"


TxRegistre::TxRegistre()
{
	usuariRepository = gcnew UsuariRepository();
}

bool TxRegistre::CheckUsername(String^ username)
{
	//Usuari^ checkuser = CheckUserBD(username);
	/*if (checkuser->username == username) return true;
	else return false;*/
	return true;
}