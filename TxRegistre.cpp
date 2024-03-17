#include "pch.h"
#include "TxRegistre.h"


TxRegistre::TxRegistre()
{
	usuariRepository = gcnew UsuariRepository();
}

bool TxRegistre::CheckUsername(String^ username)
{
	return this->usuariRepository->CheckUsuariByUser(username);
}