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

bool TxRegistre::CheckEmail(String^ email)
{
    return this->usuariRepository->CheckUsuariByEmail(email);
}

bool TxRegistre::CreateUser(String^ username, String^ email, String^ name, String^ password) 
{
	return this->usuariRepository->CreateUser(username, email, name, password);
}