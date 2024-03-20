#include "pch.h"
#include "BaixaProveidor.h"
#include "DatabaseConnector.h"
#include "Proveidor.h"
#include "BaixaProveidorService.h"
#include "ProveidorRepository.h"
#include "MessageManager.h"


void ProveidorService::BaixaProveidor(String^ name)
{
	if (!CheckIfProveidorExists(name)) {
		MessageManager::WarningMessage("El proveidor no existeix.");
		return;
	}
	proveidorRepository->BaixaProveidor(name);
	MessageManager::InfoMessage("Proveidor eliminat amb èxit.");
}

bool BaixaProveidorService::CheckIfProveidorExists(String^ name) {
	Proveidor^ proveidor = proveidorRepository->GetProveidorByName(name);

	return not System::String::IsNullOrEmpty(proveidor->GetProveidorName());
}

