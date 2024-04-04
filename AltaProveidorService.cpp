#include "pch.h"

#include "DatabaseConnector.h"
#include "AltaProveidorService.h"
#include "ProveidorRepository.h"
#include "MessageManager.h"
AltaProveidorService::AltaProveidorService()
{
	proveidorRepository = gcnew ProveidorRepository();
}
bool AltaProveidorService::AltaProveidor( String^ username, String^ email, String^ name, String^ password)
{
	try {
		if (this->CheckIfProveidorExists(username)) {
			MessageManager::WarningMessage("El proveidor ja existeix!");
			return false;
		}
		else {
			MessageManager::InfoMessage("Proveidor donat d'alta");
			return proveidorRepository->CreateNewProveidor(username, email, name, password);
			
		}
	}
	catch (Exception^ e) {
		MessageManager::ErrorMessage(e->Message);
	}

}
bool AltaProveidorService::CheckIfProveidorExists(String^ username) {

	return proveidorRepository->CheckIfProveidorExists(username);
}