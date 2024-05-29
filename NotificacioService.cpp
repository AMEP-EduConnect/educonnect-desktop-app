#include "pch.h"
#include "NotificacioService.h"
#include "DatabaseConnector.h"
#include "MessageManager.h"
using namespace System::Collections::Generic;

NotificacioService::NotificacioService() {
    notificacioRepository = gcnew NotificacioRepository();
    
}

Int64^ NotificacioService::AddNotificacio(Int64^ notification_type, Int64^ status, Int64^ source_grup_id, Int64^ source_user_id, Int64^ destination_user_id)
{
    notificacioRepository->AddNotificacio( notification_type,  status, source_grup_id,  source_user_id, destination_user_id);
    
}


List<Notificacio^>^ NotificacioService::ListNotificacions(Int64^ id_destination, Int64^ type, Int64^ status) {
    List<Notificacio^>^ notificacions = gcnew List<Notificacio^>(0);
    notificacions = notificacioRepository->GetNotificacionsByDestinationId( id_destination,  type,  status);
    return notificacions;
}

void NotificacioService::ChangeStatus(Int64^ status, Notificacio^ notificacio)
{
    notificacioRepository->ChangeStatus(status, notificacio);
}

