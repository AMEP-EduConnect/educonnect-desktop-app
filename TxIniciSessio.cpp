#include "pch.h"
#include "DatabaseConnector.h"
#include "UsuariRepository.h"
#include "TxIniciSessio.h"

TxIniciSessio::TxIniciSessio()
{
	UsuariRepository = gcnew;
}

Usuari^ TxiniciSessio::GetUsuariById(Int64^ id)
{
	return UsuariRepository->GetUsuariById(id);
}