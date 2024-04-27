#include "pch.h"
#include "AltaEspaisService.h"
#include "CurrentSession.h"
#include "DatabaseConnector.h"
#include "MessageManager.h"
AltaEspaisService::AltaEspaisService()
{
	espaisRepository = gcnew EspaisRepository();
	espais = gcnew Espais();
	usuari = gcnew Usuari();
}

bool AltaEspaisService::AltaEspai(String^ nom, Int64^ capacitat)
{
	Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
	Int64^ id_provider = currentUser->GetUserId();

	return espaisRepository->CreateEspai(nom, capacitat, id_provider);

}
