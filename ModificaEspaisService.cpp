#include "pch.h"
#include "ModificaEspaisService.h"
#include "CurrentSession.h"
#include "DatabaseConnector.h"
#include "MessageManager.h"

ModificaEspaisService::ModificaEspaisService()
{
	espaisRepository = gcnew EspaisRepository();
	espais = gcnew Espai();
	usuari = gcnew Usuari();
}

bool ModificaEspaisService::CheckNameEspai(String^ name)
{
	return false;
}

Espai^ ModificaEspaisService::GetEspaiByName(String^ name) {
	Espai^ espai = espaisRepository->GetEspaiByName(name);
	return espai;
}

bool ModificaEspaisService::UpdateEspaiCapacity (String^ name) {
	Espai^ espai = espaisRepository->GetEspaiByName(name);
	Int64^ capacity = espai->GetCapacity();
	String^ capacityString = capacity->ToString();
	if (name == "") {
		name = espai->GetName();
		
	}
	return espaisRepository->UpdateEspaiName(name);
	if (capacityString == "") {
		capacity = espai->GetCapacity();
	}

	
	return espaisRepository->UpdateEspaiCapacity(capacity);
}