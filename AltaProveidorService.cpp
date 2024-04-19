#include "pch.h"
#include "DatabaseConnector.h"
#include "AltaProveidorService.h"
#include "MessageManager.h"
AltaProveidorService::AltaProveidorService()
{
	usuariRepository = gcnew UsuariRepository();
	usuariRolRepository = gcnew UsuariRolRepository();
	credentialManagementService = gcnew CredentialManagementService();
}
bool AltaProveidorService::AltaProveidor( String^ username, String^ email, String^ name, String^ password)
{
		if (usuariRepository->CheckUsuariByUser(username) == true) {
			MessageManager::WarningMessage("Existeix un proveidor/usuari amb aquest username!");
			return false;
		}
		else {
			MessageManager::InfoMessage("Proveidor donat d'alta");
			String^ hash = credentialManagementService->HashPassword(password);
			Int64^ id_user = usuariRepository->CreateUser(username, email, name, hash);
			Int64^ id_rol = 3LL;
			return usuariRolRepository->CreateUserRol(id_user, id_rol);
		}

}
