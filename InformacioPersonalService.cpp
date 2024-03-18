#include "pch.h"
#include "DatabaseConnector.h"
#include "InformacioPersonalService.h"
#include "InformacioPersonalRepository.h"
#include "Usuari.h"

InformacioPersonalService::InformacioPersonalService()
{
	informacioPersonalRepository = gcnew InformacioPersonalRepository();
}

Usuari^ InformacioPersonalService::GetUsuariById(Int64^ id)
{
	return informacioPersonalRepository->GetUsuariById(id);
}