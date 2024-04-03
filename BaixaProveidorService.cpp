#include "pch.h"
#include "BaixaProveidorService.h"
#include "DatabaseConnector.h"
#include "ProveidorRepository.h"
#include "MessageManager.h"

BaixaProveidorService::BaixaProveidorService() {
    proveidorRepository = gcnew ProveidorRepository();
}

bool BaixaProveidorService::BaixaProveidor(String^ username) {
    if (!CheckIfProveidorExists(username)) {
        MessageManager::WarningMessage("El proveedor no existe.");
        return false; 
    }

    try {
        proveidorRepository->BaixaProveidor(username);
        return true; 
    }
    catch (Exception^ ex) {
        MessageManager::ErrorMessage("Error al eliminar el proveedor: " + ex->Message);
        return false;
    }
}

bool BaixaProveidorService::CheckIfProveidorExists(String^ username) {
    return proveidorRepository->CheckIfProveidorExists(username);
}
