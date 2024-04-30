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

bool ModificaEspaisService::UpdateEspai (String^ name, Int64^ capacity, Int64^ id_espai) {
	Espai^ espai = espaisRepository->GetEspaiByName(name);
	
	String^ capacityString = capacity->ToString();
	if (name == "") {
		name = espai->GetName();
		
	}
	
	if (capacityString == "") {
		capacity = espai->GetCapacity();
	}

	
	return espaisRepository->UpdateEspai(name, capacity, id_espai);
}