#include "pch.h"

#include "DatabaseConnector.h"
#include "Proveidor.h"
#include "AltaProveidorService.h"
#include "ProveidorRepository.h"
#include "MessageManager.h"
AltaProveidorService::AltaProveidorService()
{
	proveidorRepository = gcnew ProveidorRepository();
}
void AltaProveidorService::AltaProveidor(String^ id, String^ username, String^ password, String^ email, String^ surname)
{
	try {
		if (this->CheckIfProveidorExists(username)) {
			MessageManager::WarningMessage("El proveidor ja existeix!");
			return;
		}
		else {
			MessageManager::InfoMessage("Proveidor donat d'alta");
			proveidorRepository->AltaProveidor(id, username, password, email, surname);
		}
	}
	catch (Exception^ e) {
		MessageManager::ErrorMessage(e->Message);
	}

}
bool AltaProveidorService::CheckIfProveidorExists(String^ username) {
	Proveidor^ proveidor = proveidorRepository->GetProveidorByName(username);

	return !System::String::IsNullOrEmpty(proveidor->GetProveidorName());
}