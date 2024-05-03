#include "pch.h"
#include "AltaEspaisService.h"
#include "CurrentSession.h"
#include "DatabaseConnector.h"
#include "MessageManager.h"
AltaEspaisService::AltaEspaisService()
{
	espaisRepository = gcnew EspaisRepository();
	espais = gcnew Espai();
	usuari = gcnew Usuari();
}



bool AltaEspaisService::CheckNameEspai(String^ name)
{
	Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
	Int64^ id_provider = currentUser->GetUserId();
	bool exist = espaisRepository->CheckEspaiByName(name, id_provider);
	return false;
}

bool AltaEspaisService::AltaEspai(String^ nom, Int64^ capacitat)
{
	Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
	Int64^ id_provider = currentUser->GetUserId();

	return espaisRepository->CreateEspai(nom, capacitat, id_provider);

}
