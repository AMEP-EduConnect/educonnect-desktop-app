#include "pch.h"
#include "AltaProveidor.h"
#include "DatabaseConnector.h"
#include "Proveidor.h"
#include "AltaProveidorService.h"
#include "ProveidorRepository.h"
#include "MessageManager.h"
AltaProveidorService::AltaProveidorService()
{
	proveidorRepository = gcnew ProveidorRepository();
}
void AltaProveidorService::AltaProveidor(String^ name)
{
	try {
		if (this->CheckIfProveidorExists(name)) {
			MessageManager::WarningMessage("El proveidor ja existeix!");
			return;
		}
		else {
			MessageManager::InfoMessage("Proveidor donat d'alta");
			proveidorRepository->AltaProveidor(name);
		}
	}
	catch (Exception^ e) {
		MessageManager::ErrorMessage(e->Message);
	}

}
bool AltaProveidorService::CheckIfProveidorExists(String^ name) {
	Proveidor^ proveidor = proveidorRepository->GetProveidorByName(name);

	return not System::String::IsNullOrEmpty(proveidor->GetProveidorName());
}