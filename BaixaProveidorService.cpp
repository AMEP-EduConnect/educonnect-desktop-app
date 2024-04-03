#include "pch.h"
#include "BaixaProveidorService.h"
#include "DatabaseConnector.h"
#include "ProveidorRepository.h"
#include "MessageManager.h"

BaixaProveidorService::BaixaProveidorService() {
    proveidorRepository = gcnew ProveidorRepository();
}

bool BaixaProveidorService::BaixaProveidor(String^ username) {

    try {
        if (this->CheckIfProveidorExists(username)) {
            MessageManager::WarningMessage("El proveedor no existe.");
            return false;
        }
        else {
            proveidorRepository->BaixaProveidor(username);
            MessageManager::InfoMessage("Proveidor donat de baixa correctament");
            return true;
        }
    }
    catch (Exception^ ex) {
        MessageManager::ErrorMessage("Error al eliminar el proveedor: " + ex->Message);
        return false;
    }
}

bool BaixaProveidorService::CheckIfProveidorExists(String^ username) {
    return proveidorRepository->CheckIfProveidorExists(username);
}
